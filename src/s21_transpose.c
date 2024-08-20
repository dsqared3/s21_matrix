#include "s21_matrix.h"

// Транспонирование матрицы А заключается в замене строк этой матрицы ее
// столбцами с сохранением их номеров.

// Транспонирование матриц
int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (s21_check_null_result(A) || s21_check_col_row(A->rows, A->columns))
    res = INVALID_MATRIX;
  else {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[j][i] = A->matrix[i][j];
  }
  return res;
}
