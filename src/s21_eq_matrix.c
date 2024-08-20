#include "s21_matrix.h"

// Сравнение двух матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (A == NULL || B == NULL) {
    res = FAILURE;
  } else if (A->columns != B->columns || A->rows != B->rows)
    res = FAILURE;
  else {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) res = FAILURE;
  }
  return res;
}
