#include "matrix.h"

int matrix_exist(matrix_t *A) {
  int res = SUCCESS;
  if (A->columns <= 0 || A->rows <= 0 || A->matrix == NULL || A == NULL) {
    res = FAILURE;
  }
  return res;
}

void remove_matrix(matrix_t *A) {
  if (A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) {
        free(A->matrix[i]);
      }
    }
    free(A->matrix);
    A->matrix = NULL;
  }
  A->rows = 0;
  A->columns = 0;
}

int create_matrix(int rows, int columns, matrix_t *result) {
  int res = OK;
  if (rows <= 0 || columns <= 0) {
    res = ERR_CREATE;
  } else {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      res = ERR_CREATE;
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          remove_matrix(result);
          res = ERR_CREATE;
          break;
        }
      }
      if (!res) {
        result->rows = rows;
        result->columns = columns;
      }
    }
  }
  return res;
}

int eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (A->columns != B->columns || A->rows != B->rows || !matrix_exist(A) ||
      !matrix_exist(B)) {
    res = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (floor(A->matrix[i][j] * pow(10, 7)) !=
            floor(B->matrix[i][j] * pow(10, 7))) {
          res = FAILURE;
          break;
        }
      }
    }
  }
  return res;
}

int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (!matrix_exist(A) || !matrix_exist(B)) {
    res = ERR_CREATE;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    res = ERR_CALC;
  } else if (create_matrix(A->rows, A->columns, result)) {
    res = ERR_CREATE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return res;
}

int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (!matrix_exist(A) || !matrix_exist(B)) {
    res = ERR_CREATE;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    res = ERR_CALC;
  } else if (create_matrix(A->rows, A->columns, result)) {
    res = ERR_CREATE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return res;
}

int mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = OK;
  if (!matrix_exist(A)) {
    res = ERR_CREATE;
  } else if (create_matrix(A->rows, A->columns, result)) {
    res = ERR_CREATE;
  } else if (isnan(number) || number == INF || number == -INF) {
    res = ERR_CALC;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = number * A->matrix[i][j];
      }
    }
  }
  return res;
}

int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (!matrix_exist(A) || !matrix_exist(B)) {
    res = ERR_CREATE;
  } else if (A->columns != B->rows) {
    res = ERR_CALC;
  } else if (create_matrix(A->rows, B->columns, result)) {
    res = ERR_CREATE;
  } else {
    double sum = 0.0;
    for (int l = 0; l < result->rows; l++) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          for (int k = 0; k < A->columns; k++) {
            sum += A->matrix[i][k] * B->matrix[k][j];
          }
          result->matrix[i][j] = sum;
          sum = 0.0;
        }
      }
    }
  }
  return res;
}

int transpose(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (!matrix_exist(A)) {
    res = ERR_CREATE;
  } else if (create_matrix(A->columns, A->rows, result)) {
    res = ERR_CREATE;
  } else {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return res;
}

int calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (create_matrix(A->rows, A->columns, result)) {
    res = ERR_CREATE;
  } else if (A->rows == 1 && A->columns == 1) {
    result->matrix[0][0] = A->matrix[0][0];
  } else {
    double min = 0.0;
    matrix_t minor = {0};
    if (create_matrix(A->rows - 1, A->columns - 1, &minor)) {
      res = ERR_CREATE;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          min = 0.0;
          minor_matrix(A, &minor, i, j);
          if (determinant(&minor, &min)) {
            res = ERR_CALC;
            break;
          } else {
            result->matrix[i][j] = min * pow(-1, i + j);
            if (result->matrix[i][j] == -0) result->matrix[i][j] = 0;
          }
        }
      }
    }
    if (minor.matrix != NULL) remove_matrix(&minor);
  }
  return res;
}

int determinant(matrix_t *A, double *result) {
  int res = OK;
  if (result != NULL) *result = 0.0;
  if (!matrix_exist(A)) {
    res = ERR_CREATE;
  } else if (A->rows != A->columns) {
    res = ERR_CALC;
  } else if (A->columns == 1) {
    *result = A->matrix[0][0];
  } else if (A->columns == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else if (A->columns > 2) {
    matrix_t minor_mtrx = {0};
    if (create_matrix(A->rows - 1, A->columns - 1, &minor_mtrx)) {
      res = ERR_CREATE;
    } else {
      for (int i = 0; i < A->columns; i++) {
        double det = 0.0;
        minor_matrix(A, &minor_mtrx, i, 0);
        if (determinant(&minor_mtrx, &det)) {
          res = ERR_CALC;
          break;
        } else {
          *result += pow(-1, i) * A->matrix[i][0] * det;
        }
      }
    }
    if (minor_mtrx.matrix != NULL) remove_matrix(&minor_mtrx);
  }
  return res;
}

void minor_matrix(matrix_t *A, matrix_t *result, int rows, int columns) {
  for (int i = 0, z_i = 0; i < A->rows; i++) {
    if (i != rows) {
      for (int j = 0, z_j = 0; j < A->columns; j++) {
        if (j != columns) {
          result->matrix[z_i][z_j] = A->matrix[i][j];
          z_j++;
        }
      }
      z_i++;
    }
  }
}

int inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (!matrix_exist(A)) {
    res = ERR_CREATE;
  } else if (A->rows != A->columns) {
    res = ERR_CALC;
  } else if (A->rows == 1 && A->matrix[0][0] != 0.0) {
    if (create_matrix(A->rows, A->columns, result))
      res = ERR_CREATE;
    else
      result->matrix[0][0] = 1 / A->matrix[0][0];
  } else {
    double det = 0.0;
    if (determinant(A, &det)) {
      res = ERR_CALC;
    } else if (fabs(det) < 1e-7) {
      res = ERR_CALC;
    } else {
      matrix_t reserv_mtrx = {0};
      matrix_t reserv_mtrx2 = {0};
      if (calc_complements(A, &reserv_mtrx)) {
        res = ERR_CALC;
      } else if (transpose(&reserv_mtrx, &reserv_mtrx2)) {
        res = ERR_CALC;
      } else if (mult_number(&reserv_mtrx2, 1 / det, result)) {
        res = ERR_CALC;
      }
      if (reserv_mtrx.matrix != NULL) {
        remove_matrix(&reserv_mtrx);
      }
      if (reserv_mtrx2.matrix != NULL) {
        remove_matrix(&reserv_mtrx2);
      }
    }
  }
  return res;
}
