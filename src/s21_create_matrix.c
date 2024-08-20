#include "s21_matrix.h"

// Создание матрицы rows x columns
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = OK;
  if (s21_check_null_result(result) || s21_check_col_row(rows, columns))
    res = INVALID_MATRIX;
  else {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++)
      result->matrix[i] = calloc(columns, sizeof(double));
    result->rows = rows;
    result->columns = columns;
  }
  return res;
}
