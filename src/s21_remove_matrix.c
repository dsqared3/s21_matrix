#include "s21_matrix.h"

// Удаление матрицы (очищение памяти)
void s21_remove_matrix(matrix_t *A) {
  if (~s21_check_null_result(A)) {
    for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
    free(A->matrix);
    A->columns = 0;
    A->rows = 0;
  }
}