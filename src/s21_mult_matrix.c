#include "s21_matrix.h"

// Умножение матрицы на матрицу
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (s21_check_null_result(A) || s21_check_col_row(A->rows, A->columns) ||
      s21_check_null_result(B) || s21_check_col_row(B->rows, B->columns))
    res = INVALID_MATRIX;
  else if (A->columns != B->rows)
    res = CALCULATION_ERROR;
  else {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < result->rows; i++)
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < A->columns; k++)
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
  }
  return res;
}