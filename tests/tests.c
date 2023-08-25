#include <check.h>

#include "../matrix.h"

START_TEST(create_matrix_1) {
  int res1 = 0;
  int res2 = 0;
  int res3 = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t C = {NULL, 0, 0};
  res1 = create_matrix(5, 5, &A);
  ck_assert_int_eq(res1, 0);

  res2 = create_matrix(5, 0, &B);
  ck_assert_int_eq(res2, 1);

  res3 = create_matrix(1000, 10, &C);
  ck_assert_int_eq(res3, 0);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&C);
}
END_TEST

START_TEST(eq_matrix_1) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  res = eq_matrix(&A, &B);
  remove_matrix(&A);
  remove_matrix(&B);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(eq_matrix_2) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  create_matrix(10, 10, &A);
  create_matrix(10, 10, &B);
  res = eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_3) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  create_matrix(10, 10, &A);
  create_matrix(10, 10, &B);
  A.matrix[0][0] = 1.0000000f;
  res = eq_matrix(&A, &B);
  remove_matrix(&A);
  remove_matrix(&B);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(eq_matrix_4) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  create_matrix(10, 10, &A);
  create_matrix(10, 10, &B);
  A.matrix[0][0] = 1.0000010f;
  B.matrix[0][0] = 1.0000001f;
  res = eq_matrix(&A, &B);
  remove_matrix(&A);
  remove_matrix(&B);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(eq_matrix_5) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  create_matrix(15, 10, &A);
  create_matrix(10, 15, &B);
  A.matrix[0][0] = 1.0000001f;
  B.matrix[0][0] = 1.0000001f;
  res = eq_matrix(&A, &B);
  remove_matrix(&A);
  remove_matrix(&B);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(eq_matrix_6) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  create_matrix(15, 15, &A);
  create_matrix(15, 15, &B);
  A.matrix[0][0] = 1.0000001f;
  B.matrix[0][0] = 1.0000001f;
  res = eq_matrix(&A, &B);
  remove_matrix(&A);
  remove_matrix(&B);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(eq_matrix_7) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  create_matrix(15, 15, &A);
  create_matrix(15, 15, &B);
  A.matrix[0][0] = 1.0000001f;
  B.matrix[0][0] = 1.0000001f;
  res = eq_matrix(&A, &B);
  remove_matrix(&A);
  remove_matrix(&B);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(eq_matrix_8) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(5, 5, &A);
  create_matrix(5, 5, &B);

  A.matrix[0][0] = 1.123f;
  A.matrix[0][1] = 3.123000f;
  A.matrix[0][2] = 1.12555f;
  A.matrix[0][3] = 1.123789f;
  A.matrix[0][4] = 123.123312f;
  A.matrix[1][0] = 1.123f;
  A.matrix[1][1] = 3.123000f;
  A.matrix[1][2] = 1.12555f;
  A.matrix[1][3] = 1.123789f;
  A.matrix[1][4] = 123.123312f;
  A.matrix[2][0] = 1.123f;
  A.matrix[2][1] = 3.123000f;
  A.matrix[2][2] = 1.12555f;
  A.matrix[2][3] = 1.123789f;
  A.matrix[2][4] = 123.123312f;
  A.matrix[3][0] = 1.123f;
  A.matrix[3][1] = 3.123000f;
  A.matrix[3][2] = 1.12555f;
  A.matrix[3][3] = 1.123789f;
  A.matrix[3][4] = 123.123312f;
  A.matrix[4][0] = 1.123f;
  A.matrix[4][1] = 3.123000f;
  A.matrix[4][2] = 1.12555f;
  A.matrix[4][3] = 1.123789f;
  A.matrix[4][4] = 123.123312f;

  sum_matrix(&A, &B, &result);

  res = eq_matrix(&A, &result);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(eq_matrix_9) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(5, 5, &A);
  create_matrix(5, 5, &B);

  int k = 0;

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = 1.0f + A.matrix[i][j] + 1.123f + 0.001f;
    }
    A.matrix[i][k] = 1.123f + 0.001f + B.matrix[i][k];
    k++;
  }
  sub_matrix(&A, &B, &result);
  res = eq_matrix(&A, &result);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(eq_matrix_10) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  create_matrix(2, 2, &result_full);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = j;
    }
  }

  for (int i = 0; (i < A.rows); i++) {
    for (int j = 0; j < A.columns; j++) {
      result_full.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  }

  ck_assert_int_eq(sum_matrix(&A, &B, &result), 0);
  ck_assert_int_eq(eq_matrix(&result_full, &result), 1);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sum_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  create_matrix(5, 5, &A);
  create_matrix(5, 5, &B);
  create_matrix(5, 5, &result_full);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = j + 1 + 0.0000001;
      B.matrix[i][j] = j + 1 + 0.0000001;
      result_full.matrix[i][j] = j + 1 + A.matrix[i][j] + 0.0000001;
    }
  }

  ck_assert_int_eq(sum_matrix(&A, &B, &result), 0);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sum_matrix_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  create_matrix(2, 2, &result_full);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = j + 1 + 0.0000001;
      B.matrix[i][j] = j + 1 + 0.0000001;
      result_full.matrix[i][j] = j + 1 + A.matrix[i][j] + 0.0000001;
    }
  }

  A.columns = 0;
  B.rows = -1;
  ck_assert_int_eq(eq_matrix(&A, &B), 0);

  A.columns = 2;
  B.rows = 2;

  ck_assert_int_eq(sum_matrix(&A, &B, &result), 0);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sum_matrix_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  create_matrix(2, 2, &result_full);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = j + 1 + 0.0000001;
      B.matrix[i][j] = j + 1 + 0.0000001;
      result_full.matrix[i][j] = j + 1 + A.matrix[i][j] + 0.0000001;
    }
  }

  A.columns = 0;
  B.rows = -1;
  ck_assert_int_eq(sum_matrix(&A, &B, &result), 1);

  A.columns = 1;
  B.rows = 2;
  ck_assert_int_eq(sum_matrix(&A, &B, &result), 2);

  A.columns = 2;
  B.rows = 2;
  ck_assert_int_eq(sum_matrix(&A, &B, &result), 0);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sum_matrix_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};

  create_matrix(14, 14, &A);
  create_matrix(14, 14, &B);
  create_matrix(14, 14, &result_full);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = j + 1 + 0.0000001;
      B.matrix[i][j] = j + 1 + 0.0000001;
      result_full.matrix[i][j] = j + 1 + A.matrix[i][j] + 0.0000001;
    }
  }

  ck_assert_int_eq(sum_matrix(&A, &B, &result), 0);
  remove_matrix(&B);

  ck_assert_int_eq(sub_matrix(&A, &result, &B), 0);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      result_full.matrix[i][j] = A.matrix[i][j] - result.matrix[i][j];
      ck_assert_double_eq(B.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sum_matrix_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};

  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  create_matrix(2, 2, &result_full);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = j + 1 + 81230.0000001;
      B.matrix[i][j] = j + 1 + 2.0000001;
      result_full.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  }

  ck_assert_int_eq(sum_matrix(&A, &B, &result), 0);
  remove_matrix(&B);
  ck_assert_int_eq(sub_matrix(&A, &result, &B), 0);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      result_full.matrix[i][j] = A.matrix[i][j] - result.matrix[i][j];
      ck_assert_double_eq(B.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sub_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};

  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  create_matrix(2, 2, &result_full);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = j + 1 + 81230.0000001;
      B.matrix[i][j] = j + 1 + 2.0000001;
      result_full.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  }

  ck_assert_int_eq(sub_matrix(&A, &B, &result), 0);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sub_matrix_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};

  create_matrix(2, 3, &A);
  create_matrix(2, 3, &B);
  create_matrix(2, 3, &result_full);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = j + 1 + 81230.0000001;
      B.matrix[i][j] = j + 1 + 2.0000001;
      result_full.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  }

  ck_assert_int_eq(sub_matrix(&A, &B, &result), 0);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(sub_matrix_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(3, 3, &A);
  create_matrix(2, 3, &B);

  A.rows = 0;
  B.columns = -1;

  ck_assert_int_eq(sub_matrix(&A, &B, &result), 1);

  A.rows = 3;
  B.columns = 3;

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(3, 2, &A);
  create_matrix(3, 3, &B);

  ck_assert_int_eq(sub_matrix(&A, &B, &result), 2);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(4, 3, &A);
  create_matrix(4, 3, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1.21030120f;
      B.matrix[i][j] = 1.21030120f;
    }
  }

  ck_assert_int_eq(sub_matrix(&A, &B, &result), 0);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_0) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  double res = INF;
  create_matrix(4, 3, &A);
  create_matrix(4, 3, &result_full);

  ck_assert_int_eq(mult_number(&A, res, &result), 2);
  remove_matrix(&A);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(mult_number_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  double res = 5.123f;
  create_matrix(4, 3, &A);
  create_matrix(4, 3, &result_full);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1.21030120f;
      result_full.matrix[i][j] = res * A.matrix[i][j];
    }
  }

  ck_assert_int_eq(mult_number(&A, res, &result), 0);
  remove_matrix(&A);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(mult_number_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  double res = 5.123f;
  create_matrix(4, 3, &A);
  create_matrix(4, 3, &result_full);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1.21030120f;
      result_full.matrix[i][j] = res * A.matrix[i][j];
    }
  }

  ck_assert_int_eq(mult_number(&A, res, &result), 0);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], result_full.matrix[i][j]);
    }
  }

  remove_matrix(&A);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(mult_number_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  double res = 5.123f;
  create_matrix(4, 3, &A);
  create_matrix(4, 3, &result_full);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1.21030120f;
      result_full.matrix[i][j] = res * A.matrix[i][j];
    }
  }
  A.rows = -1;
  ck_assert_int_eq(mult_number(&A, res, &result), 1);
  A.rows = 4;

  remove_matrix(&A);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(mult_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(4, 3, &A);
  create_matrix(4, 3, &B);

  ck_assert_int_eq(mult_matrix(&A, &B, &result), 2);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);

  ck_assert_int_eq(mult_matrix(&A, &B, &result), 0);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t result_full;
  create_matrix(3, 2, &A);
  create_matrix(2, 3, &B);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 8;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 3;
  B.matrix[0][0] = 5;
  B.matrix[0][1] = 1;
  B.matrix[0][2] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 7;
  B.matrix[1][2] = 3;
  create_matrix(3, 3, &result_full);
  result_full.matrix[0][0] = 3;
  result_full.matrix[0][1] = 7;
  result_full.matrix[0][2] = 3;
  result_full.matrix[1][0] = 34;
  result_full.matrix[1][1] = 58;
  result_full.matrix[1][2] = 28;
  result_full.matrix[2][0] = 44;
  result_full.matrix[2][1] = 28;
  result_full.matrix[2][2] = 23;

  ck_assert_int_eq(mult_matrix(&A, &B, &result), 0);

  ck_assert_int_eq(eq_matrix(&result_full, &result), 1);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(mult_matrix_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(2, 0, &A);
  create_matrix(2, 2, &B);

  ck_assert_int_eq(mult_matrix(&A, &B, &result), 1);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(2, 1, &A);
  create_matrix(2, 2, &B);

  ck_assert_int_eq(mult_matrix(&A, &B, &result), 2);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(transpose_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result1 = {NULL, 0, 0};
  matrix_t result2 = {NULL, 0, 0};
  matrix_t result_full = {NULL, 0, 0};
  create_matrix(3, 2, &A);
  create_matrix(2, 3, &B);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 8;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 3;

  B.matrix[0][0] = 5;
  B.matrix[0][1] = 1;
  B.matrix[0][2] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 7;
  B.matrix[1][2] = 3;

  ck_assert_int_eq(mult_matrix(&A, &B, &result1), 0);

  create_matrix(3, 3, &result_full);
  result_full.matrix[0][0] = 3;
  result_full.matrix[0][1] = 34;
  result_full.matrix[0][2] = 44;
  result_full.matrix[1][0] = 7;
  result_full.matrix[1][1] = 58;
  result_full.matrix[1][2] = 28;
  result_full.matrix[2][0] = 3;
  result_full.matrix[2][1] = 28;
  result_full.matrix[2][2] = 23;

  ck_assert_int_eq(transpose(&result1, &result2), 0);

  ck_assert_int_eq(eq_matrix(&result_full, &result2), 1);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result1);
  remove_matrix(&result2);
  remove_matrix(&result_full);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(3, 5, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[0][4] = 5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 7;
  A.matrix[1][2] = 8;
  A.matrix[1][3] = 9;
  A.matrix[1][4] = 10;
  A.matrix[2][0] = 11;
  A.matrix[2][1] = 12;
  A.matrix[2][2] = 13;
  A.matrix[2][3] = 14;
  A.matrix[2][4] = 15;
  ck_assert_int_eq(transpose(&A, &result), 0);
  remove_matrix(&A);
  remove_matrix(&result);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(3, 5, &A);
  A.rows = 0;
  A.columns = -1;
  ck_assert_int_eq(transpose(&A, &result), 1);
  A.rows = 3;
  A.columns = 5;
  remove_matrix(&A);
  remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  create_matrix(2, 2, &result);
  result.matrix[0][0] = 4.0;
  result.matrix[0][1] = -3.0;
  result.matrix[1][0] = -2.0;
  result.matrix[1][1] = 1.0;

  calc_complements(&A, &B);

  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++)
      ck_assert_double_eq(B.matrix[i][j], result.matrix[i][j]);
  }

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(2, 3, &A);

  create_matrix(3, 2, &result);

  ck_assert_int_eq(calc_complements(&A, &B), 2);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  create_matrix(2, 3, &A);

  create_matrix(3, 2, &result);

  A.rows = 0;
  ck_assert_int_eq(calc_complements(&A, &B), 1);

  A.rows = 2;

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(determinant_0) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  double res1 = 0.0;

  ck_assert_int_eq(determinant(&A, &res1), 1);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(determinant_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  double res1 = 0.0;
  double res2 = 0.0;
  create_matrix(2, 2, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  create_matrix(2, 2, &result);
  result.matrix[0][0] = 4.0;
  result.matrix[0][1] = -3.0;
  result.matrix[1][0] = -2.0;
  result.matrix[1][1] = 1.0;

  ck_assert_int_eq(calc_complements(&A, &B), 0);

  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++)
      ck_assert_double_eq(B.matrix[i][j], result.matrix[i][j]);
  }

  res1 = (A.matrix[0][0] * B.matrix[0][0]) + (A.matrix[0][1] * B.matrix[0][1]);
  ck_assert_int_eq(determinant(&A, &res2), 0);

  ck_assert_double_eq(res1, res2);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  double res = 0.0f;
  create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.0;

  create_matrix(1, 1, &B);
  B.matrix[0][0] = 1.0;

  ck_assert_int_eq(calc_complements(&A, &result), 0);

  ck_assert_double_eq(B.matrix[0][0], result.matrix[0][0]);

  ck_assert_int_eq(determinant(&A, &res), 0);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  // double res1 = 0.0;
  // double res2 = 0.0;
  create_matrix(5, 5, &A);
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 4.0;
  A.matrix[0][3] = 5.0001;
  A.matrix[0][4] = 10.0123;

  A.matrix[1][0] = 11.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.00003;
  A.matrix[1][3] = 8.0;
  A.matrix[1][4] = 9.003;

  A.matrix[2][0] = 12.0;
  A.matrix[2][1] = 5.0;
  A.matrix[2][2] = 0.0;
  A.matrix[2][3] = 3.0;
  A.matrix[2][4] = 2.003;

  A.matrix[3][0] = 3.0;
  A.matrix[3][1] = 5.0;
  A.matrix[3][2] = 9.00003;
  A.matrix[3][3] = 3.0;
  A.matrix[3][4] = 10.003;

  A.matrix[4][0] = 7.0;
  A.matrix[4][1] = 8.0;
  A.matrix[4][2] = 3.00003;
  A.matrix[4][3] = 4.0;
  A.matrix[4][4] = 8.003;

  ck_assert_int_eq(calc_complements(&A, &result), 0);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(3, 3, &A);
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;

  create_matrix(3, 3, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = -1.0;
  B.matrix[0][2] = 1.0;
  B.matrix[1][0] = -38.0;
  B.matrix[1][1] = 41.0;
  B.matrix[1][2] = -34.0;
  B.matrix[2][0] = 27.0;
  B.matrix[2][1] = -29.0;
  B.matrix[2][2] = 24.0;
  ck_assert_int_eq(inverse_matrix(&A, &result), 0);

  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++)
      ck_assert_double_eq(B.matrix[i][j], result.matrix[i][j]);
  }

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(1, 1, &A);
  A.matrix[0][0] = 2.0;
  create_matrix(1, 1, &B);
  B.matrix[0][0] = 0.5;
  ck_assert_int_eq(inverse_matrix(&A, &result), 0);
  ck_assert_double_eq(B.matrix[0][0], result.matrix[0][0]);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result1 = {NULL, 0, 0};
  matrix_t result2 = {NULL, 0, 0};

  create_matrix(5, 5, &A);

  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 4.0;
  A.matrix[0][3] = 5.0;
  A.matrix[0][4] = 10.0;

  A.matrix[1][0] = 11.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[1][3] = 8.0;
  A.matrix[1][4] = 9.0;

  A.matrix[2][0] = 12.0;
  A.matrix[2][1] = 5.0;
  A.matrix[2][2] = 0.0;
  A.matrix[2][3] = 3.0;
  A.matrix[2][4] = 2.0;

  A.matrix[3][0] = 3.0;
  A.matrix[3][1] = 5.0;
  A.matrix[3][2] = 9.0;
  A.matrix[3][3] = 3.0;
  A.matrix[3][4] = 10.0;

  A.matrix[4][0] = 7.0;
  A.matrix[4][1] = 8.0;
  A.matrix[4][2] = 3.0;
  A.matrix[4][3] = 4.0;
  A.matrix[4][4] = 8.0;

  create_matrix(5, 5, &B);
  B.matrix[0][0] = 0.0786026;
  B.matrix[0][1] = -0.0826783;
  B.matrix[0][2] = 0.2126638;
  B.matrix[0][3] = 0.0679767;
  B.matrix[0][4] = -0.1433770;

  B.matrix[1][0] = -0.1965066;
  B.matrix[1][1] = 0.0733624;
  B.matrix[1][2] = -0.1816594;
  B.matrix[1][3] = -0.0532751;
  B.matrix[1][4] = 0.2751092;

  B.matrix[2][0] = -0.1659389;
  B.matrix[2][1] = 0.1152838;
  B.matrix[2][2] = -0.0711790;
  B.matrix[2][3] = 0.1305677;
  B.matrix[2][4] = -0.0676856;

  B.matrix[3][0] = -0.1703057;
  B.matrix[3][1] = 0.3569141;
  B.matrix[3][2] = -0.3441048;
  B.matrix[3][3] = -0.2195051;
  B.matrix[3][4] = 0.1717613;

  B.matrix[4][0] = 0.2751092;
  B.matrix[4][1] = -0.2227074;
  B.matrix[4][2] = 0.1943231;
  B.matrix[4][3] = 0.0545852;
  B.matrix[4][4] = -0.0851528;

  ck_assert_int_eq(inverse_matrix(&A, &result1), 0);
  ck_assert_int_eq(inverse_matrix(&B, &result2), 0);
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++)
      ck_assert_double_eq_tol(A.matrix[i][j], result2.matrix[i][j], 1e-5);
  }
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result1);
  remove_matrix(&result2);
}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  ck_assert_int_eq(inverse_matrix(&A, &result), 1);

  remove_matrix(&A);
  remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(3, 4, &A);

  ck_assert_int_eq(inverse_matrix(&A, &result), 2);

  remove_matrix(&A);
  remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_6) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.5;

  ck_assert_int_eq(inverse_matrix(&A, &result), 0);

  remove_matrix(&A);
  remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(1, 1, &A);

  ck_assert_int_eq(inverse_matrix(&A, &result), 2);

  remove_matrix(&A);
  remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_8) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  create_matrix(3, 3, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;

  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;

  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;

  ck_assert_int_eq(inverse_matrix(&A, &result), 2);

  remove_matrix(&A);
  remove_matrix(&result);
}
END_TEST

Suite *create_matrix(void) {
  Suite *suite = suite_create("ts_create_matrix");
  TCase *test_case = tcase_create("tc_create_matrix");
  tcase_add_test(test_case, create_matrix_1);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *eq_matrix(void) {
  Suite *suite = suite_create("ts_eq_matrix");
  TCase *test_case = tcase_create("tc_eq_matrix");
  tcase_add_test(test_case, eq_matrix_1);
  tcase_add_test(test_case, eq_matrix_2);
  tcase_add_test(test_case, eq_matrix_3);
  tcase_add_test(test_case, eq_matrix_4);
  tcase_add_test(test_case, eq_matrix_5);
  tcase_add_test(test_case, eq_matrix_6);
  tcase_add_test(test_case, eq_matrix_7);
  tcase_add_test(test_case, eq_matrix_8);
  tcase_add_test(test_case, eq_matrix_9);
  tcase_add_test(test_case, eq_matrix_10);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *sum_matrix(void) {
  Suite *suite = suite_create("ts_sum_matrix");
  TCase *test_case = tcase_create("tc_sum_matrix");
  tcase_add_test(test_case, sum_matrix_1);
  tcase_add_test(test_case, sum_matrix_2);
  tcase_add_test(test_case, sum_matrix_3);
  tcase_add_test(test_case, sum_matrix_4);
  tcase_add_test(test_case, sum_matrix_5);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *sub_matrix(void) {
  Suite *suite = suite_create("ts_sub_matrix");
  TCase *test_case = tcase_create("tc_sub_matrix");
  tcase_add_test(test_case, sub_matrix_1);
  tcase_add_test(test_case, sub_matrix_2);
  tcase_add_test(test_case, sub_matrix_3);
  tcase_add_test(test_case, sub_matrix_4);
  tcase_add_test(test_case, sub_matrix_5);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *mult_number(void) {
  Suite *suite = suite_create("ts_mult_number");
  TCase *test_case = tcase_create("tc_mult_number");
  tcase_add_test(test_case, mult_number_0);
  tcase_add_test(test_case, mult_number_1);
  tcase_add_test(test_case, mult_number_2);
  tcase_add_test(test_case, mult_number_3);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *mult_matrix(void) {
  Suite *suite = suite_create("ts_mult_matrix");
  TCase *test_case = tcase_create("tc_mult_matrix");
  tcase_add_test(test_case, mult_matrix_1);
  tcase_add_test(test_case, mult_matrix_2);
  tcase_add_test(test_case, mult_matrix_3);
  tcase_add_test(test_case, mult_matrix_4);
  tcase_add_test(test_case, mult_matrix_5);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *transpose(void) {
  Suite *suite = suite_create("ts_transpose");
  TCase *test_case = tcase_create("tc_transpose");
  tcase_add_test(test_case, transpose_1);
  tcase_add_test(test_case, transpose_2);
  tcase_add_test(test_case, transpose_3);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *calc_complements(void) {
  Suite *suite = suite_create("ts_calc_complements");
  TCase *test_case = tcase_create("tc_calc_complements");
  tcase_add_test(test_case, calc_complements_1);
  tcase_add_test(test_case, calc_complements_2);
  tcase_add_test(test_case, calc_complements_3);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *determinant(void) {
  Suite *suite = suite_create("ts_determinant");
  TCase *test_case = tcase_create("tc_determinant");
  tcase_add_test(test_case, determinant_0);
  tcase_add_test(test_case, determinant_1);
  tcase_add_test(test_case, determinant_2);
  tcase_add_test(test_case, determinant_3);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *inverse_matrix(void) {
  Suite *suite = suite_create("ts_inverse_matrix");
  TCase *test_case = tcase_create("tc_inverse_matrix");
  tcase_add_test(test_case, inverse_matrix_1);
  tcase_add_test(test_case, inverse_matrix_2);
  tcase_add_test(test_case, inverse_matrix_3);
  tcase_add_test(test_case, inverse_matrix_4);
  tcase_add_test(test_case, inverse_matrix_5);
  tcase_add_test(test_case, inverse_matrix_6);
  tcase_add_test(test_case, inverse_matrix_7);
  tcase_add_test(test_case, inverse_matrix_8);
  suite_add_tcase(suite, test_case);

  return suite;
}

int main() {
  Suite *test_suites[] = {
      create_matrix(),    eq_matrix(),   sum_matrix(), sub_matrix(),
      mult_number(),      mult_matrix(), transpose(),  inverse_matrix(),
      calc_complements(), determinant(), NULL};
  int failed = 0;

  for (Suite **s = test_suites; *s != NULL; s++) {
    SRunner *runner = srunner_create(*s);
    srunner_run_all(runner, CK_NORMAL);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return failed;
}
