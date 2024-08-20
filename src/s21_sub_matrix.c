#include "s21_matrix.h"

// Разность матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (s21_check_null_result(A) || s21_check_col_row(A->columns, A->rows) ||
      s21_check_null_result(B) || s21_check_col_row(B->columns, B->rows))
    res = INVALID_MATRIX;
  else if (A->columns != B->columns || A->rows != B->rows)
    res = CALCULATION_ERROR;
  else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
  }
  return res;
}