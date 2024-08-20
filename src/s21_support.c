#include "s21_matrix.h"

// Проверяем количество стобцов и строчек было >=1
int s21_check_col_row(int rows, int columns) { return rows < 1 || columns < 1; }

// Проверяем указель result != NULL
int s21_check_null_result(matrix_t *result) { return result == NULL; }

// Устанавливаем значение в матрицу для теста
void s21_set(double *number, matrix_t *A) {
  int count = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = number[count++];
    }
  }
}

// Устанавливаем рандонмное значение
double get_rand(double min, double max) {
  double val = (double)rand() / RAND_MAX;
  return min + val * (max - min);
}
