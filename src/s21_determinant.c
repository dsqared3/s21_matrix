#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = OK;
  if (s21_check_null_result(A) || s21_check_col_row(A->rows, A->columns))
    res = INVALID_MATRIX;
  else if (A->rows != A->columns)
    res = CALCULATION_ERROR;
  else {
    *result = s21_recurs_determinant(A, A->columns);
  }
  return res;
}
double s21_recurs_determinant(matrix_t *A, int size) {
  double deter = 0;
  if (size == 1)
    deter = A->matrix[0][0];
  else if (size == 2)
    deter =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  else if (size == 3)
    deter = A->matrix[0][0] * A->matrix[1][1] * A->matrix[2][2] +
            A->matrix[2][0] * A->matrix[0][1] * A->matrix[1][2] +
            A->matrix[1][0] * A->matrix[2][1] * A->matrix[0][2] -
            A->matrix[2][0] * A->matrix[1][1] * A->matrix[0][2] -
            A->matrix[0][0] * A->matrix[2][1] * A->matrix[1][2] -
            A->matrix[1][0] * A->matrix[0][1] * A->matrix[2][2];
  else {
    matrix_t B;
    s21_create_matrix(size, size, &B);
    int sign = 1;
    for (int i = 0; i < size; i++) {
      s21_transform_minor(A, &B, 0, i);
      deter += sign * A->matrix[0][i] * s21_recurs_determinant(&B, size - 1);
      sign *= -1;
    }
    s21_remove_matrix(&B);
  }
  return deter;
}

void s21_transform_minor(matrix_t *A, matrix_t *B, int i_res, int j_res) {
  int subRow = 0, subCol = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == i_res) continue;
    for (int j = 0; j < A->columns; j++) {
      if (j == j_res)
        continue;
      else {
        subCol = j < j_res ? j : j - 1;
        B->matrix[subRow][subCol] = A->matrix[i][j];
        subCol++;
      }
    }
    subRow = i < i_res ? i : i - 1;
    if (i != i_res) subRow++;
  }
}