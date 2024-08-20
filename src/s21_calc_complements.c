
#include "s21_matrix.h"
// Минором M(i,j) называется определитель (n-1)-го порядка, полученный
// вычёркиванием из матрицы A i-й строки и j-го столбца.

// Минор матрицы и матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK, sign = OK;
  if (s21_check_null_result(A) || s21_check_col_row(A->rows, A->columns))
    res = INVALID_MATRIX;
  else if (A->rows != A->columns)
    res = CALCULATION_ERROR;
  else if (A->rows == 1) {
    s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = A->matrix[0][0];
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < result->rows; i++)
      for (int j = 0; j < result->columns; j++) {
        matrix_t B = {0};
        s21_create_matrix(A->rows - 1, A->columns - 1, &B);
        s21_transform_minor(A, &B, i, j);
        if ((i + j) % 2 == 0)
          sign = 1;
        else
          sign = -1;
        result->matrix[i][j] =
            sign * s21_recurs_determinant(&B, A->columns - 1);
        s21_remove_matrix(&B);
      }
  }
  return res;
}
