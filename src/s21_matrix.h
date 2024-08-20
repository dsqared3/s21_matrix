#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// all operation
#define OK 0
#define INVALID_MATRIX 1
#define CALCULATION_ERROR 2

// Comparison matrix
#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

//--------------------Main function---------------------------//
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

//--------------------Suport function---------------------------//
int s21_check_col_row(int rows, int columns);
int s21_check_null_result(matrix_t *result);
void s21_print_matrix(matrix_t result);
void s21_set(double *nums, matrix_t *A);
double get_rand(double min, double max);
void s21_transform_minor(matrix_t *A, matrix_t *B, int i_res, int j_res);
double s21_recurs_determinant(matrix_t *A, int size);

#endif
