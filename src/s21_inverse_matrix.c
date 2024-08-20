#include "s21_matrix.h"

// Матрицу A в степени -1 называют обратной к квадратной матрице А, если
// произведение этих матриц равняется единичной матрице.

// Обратной матрицы не существует, если определитель равен 0.

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;
  double determ = OK;
  s21_determinant(A, &determ);
  if (s21_check_null_result(A) || s21_check_col_row(A->rows, A->columns))
    res = INVALID_MATRIX;
  else if (A->rows != A->columns || fabs(determ) < 1e-7)
    res = CALCULATION_ERROR;
  else {
    if (A->rows == 1) {
      s21_create_matrix(1, 1, result);
      result->matrix[0][0] = 1 / determ;
    } else {
      matrix_t M = {0};  // Матрица миноров
      s21_calc_complements(A, &M);
      matrix_t T = {0};  // Матрица транспонирования миноров
      s21_transpose(&M, &T);
      s21_mult_number(&T, 1 / determ, result);
      s21_remove_matrix(&M);
      s21_remove_matrix(&T);
    }
  }
  return res;
}
