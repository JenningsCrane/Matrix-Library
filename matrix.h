#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define ERR_CREATE 1
#define ERR_CALC 2

#define INF 1.0 / 0.0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

void remove_matrix(matrix_t *A);
int matrix_exist(matrix_t *A);
int eq_matrix(matrix_t *A, matrix_t *B);
int create_matrix(int rows, int columns, matrix_t *result);
int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int mult_number(matrix_t *A, double number, matrix_t *result);
int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int transpose(matrix_t *A, matrix_t *result);
int calc_complements(matrix_t *A, matrix_t *result);
int determinant(matrix_t *A, double *result);
void minor_matrix(matrix_t *A, matrix_t *result, int n, int m);
int inverse_matrix(matrix_t *A, matrix_t *result);

#endif // MATRIX_H
