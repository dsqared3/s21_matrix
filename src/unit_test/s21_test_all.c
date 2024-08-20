#include "s21_unit_tests.h"

// ------------------------ create matrix -----------------------//
START_TEST(test_create_1) {
  const int rows = 123;
  const int columns = 123;
  matrix_t matrix = {0};
  ck_assert_int_eq(s21_create_matrix(rows, columns, &matrix), 0);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_2) {
  const int rows = 123;
  const int columns = 0;
  matrix_t matrix = {0};
  ck_assert_int_eq(s21_create_matrix(rows, columns, &matrix), INVALID_MATRIX);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_3) {
  const int rows = 0;
  const int columns = 123;
  matrix_t matrix = {0};
  ck_assert_int_eq(s21_create_matrix(rows, columns, &matrix), INVALID_MATRIX);
  s21_remove_matrix(&matrix);
}
END_TEST

// ------------------------ remove matrix -----------------------//

START_TEST(test_remove_1) {
  const int rows = 123;
  const int columns = 123;
  matrix_t matrix = {0};
  s21_create_matrix(rows, columns, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
}
END_TEST

// ------------------------ equal matrix -----------------------//

START_TEST(test_eq_1) {
  int res = s21_eq_matrix(NULL, NULL);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_eq_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(100, 100, &A);
  s21_create_matrix(100, 100, &B);
  A.rows = 1;
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  A.rows = 100;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 2, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_4) {
  matrix_t A;
  matrix_t B;
  double nums[4] = {1.23456789, 1.23456789, 1.23456789, 1.23456789};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_set(nums, &A);
  s21_set(nums, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_5) {
  matrix_t A;
  matrix_t B;
  double A_nums[4] = {1.23456789, 1.23456789, 1.23456789, 1.23456789};
  double B_nums[4] = {1.23456789, 1.23456789, 1.23456789, 1.23456789};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_6) {
  matrix_t A;
  matrix_t B;
  double A_nums[4] = {1, 2, 3, 4};
  double B_nums[4] = {1, 2, 3, 4};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_7) {
  matrix_t A;
  matrix_t B;
  double A_nums[4] = {1.2345678, 1.2345678, 1.2345678, 1.2345678};
  double B_nums[4] = {1.234567, 1.234567, 1.234567, 1.234567};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// ------------------------ summa matrix -----------------------//

START_TEST(test_sum_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), INVALID_MATRIX);
}
END_TEST

START_TEST(test_sum_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t eq_matrix = {0};
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(1, 2, &B);
  s21_create_matrix(1, 2, &eq_matrix);
  double A_nums[3] = {1, 2, 3};
  double B_nums[3] = {1, 2, 3};
  double eq_matrix_nums[3] = {2, 4, 6};
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  s21_set(eq_matrix_nums, &eq_matrix);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

// ------------------------ sub matrix -----------------------//

START_TEST(test_sub_1) {
  matrix_t A;
  matrix_t C;
  int result = s21_sub_matrix(NULL, &A, &C);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_sub_2) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);
  B.rows = 0;
  int result = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(result, 1);
  B.rows = 10;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 10, &B);
  int result = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(result, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_4) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t first = {0};
  s21_create_matrix(rows, cols, &first);
  matrix_t second = {0};
  s21_create_matrix(rows, cols, &second);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      first.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      second.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      check.matrix[i][j] = first.matrix[i][j] - second.matrix[i][j];
    }
  }
  matrix_t res = {0};
  ck_assert_int_eq(s21_sub_matrix(&first, &second, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);
  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

// ------------------------ mult number matrix -----------------------//

START_TEST(test_mult_1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  double number = 2;
  matrix_t first = {0};
  s21_create_matrix(rows, cols, &first);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      first.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      check.matrix[i][j] = first.matrix[i][j] * number;
    }
  }
  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_number(&first, number, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);
  s21_remove_matrix(&first);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(test_mult_2) {
  matrix_t A;
  int result = s21_mult_number(NULL, 1, &A);
  ck_assert_int_eq(result, 1);
}
END_TEST

// ------------------------ mult matrix -----------------------//
START_TEST(test_mult_mat_1) {
  matrix_t A;
  int result = s21_mult_matrix(NULL, &A, &A);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_mult_mat_2) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);
  B.rows = 0;
  int result = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result, 1);
  B.rows = 10;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_mat_3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &B);
  int result = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_mat_4) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &D);
  double A_number[4] = {1, 2, 3, 4};
  double B_number[4] = {1, 2, 3, 4};
  double D_number[4] = {7, 10, 15, 22};
  s21_set(A_number, &A);
  s21_set(B_number, &B);
  s21_set(D_number, &D);
  int result = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(s21_eq_matrix(&C, &D), 1);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

// ------------------------ trans matrix -----------------------//
START_TEST(test_transp_1) {
  matrix_t A;
  int res = s21_transpose(NULL, &A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_transp_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 10, &A);
  A.rows = 0;
  int res = s21_transpose(&A, &B);
  ck_assert_int_eq(res, 1);
  A.rows = 10;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_transp_3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  double A_nums[6] = {1, 2, 3, 4, 5, 6};
  double result_nums[6] = {1, 4, 2, 5, 3, 6};
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &C);
  s21_set(A_nums, &A);
  s21_set(result_nums, &C);
  int res = s21_transpose(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&C, &B), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_transp_4) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  double A_nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double result_nums[9] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  s21_set(A_nums, &A);
  s21_set(result_nums, &C);
  int res = s21_transpose(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&C, &B), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_transp_5) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  double A_nums[6] = {1, 2, 3, 4, 5, 6};
  double result_nums[6] = {1, 3, 5, 2, 4, 6};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &C);
  s21_set(A_nums, &A);
  s21_set(result_nums, &C);
  int res = s21_transpose(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&C, &B), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST
// ------------------------ determ matrix -----------------------//

START_TEST(test_determ_1) {
  int result = s21_determinant(NULL, NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_determ_2) {
  matrix_t A;
  double det;
  s21_create_matrix(1, 1, &A);
  A.rows = 0;
  int res = s21_determinant(&A, &det);
  ck_assert_int_eq(res, 1);
  A.rows = 1;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determ_3) {
  matrix_t A;
  double det;
  s21_create_matrix(1, 2, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determ_4) {
  matrix_t A;
  double det;
  double det_true = 123.123;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 123.123;
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+08);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determ_5) {
  matrix_t A;
  double det;
  double det_true = -347879921061.47;
  double A_nums[9] = {18248.2488, 91293.124898, 300.1,  390.1123, 44.5, 0,
                      1,          1238.4,       9999.99};
  s21_create_matrix(3, 3, &A);
  s21_set(A_nums, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+07);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determ_6) {
  matrix_t A;
  double det;
  double det_true = -40;
  double A_nums[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  s21_create_matrix(3, 3, &A);
  s21_set(A_nums, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+07);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determ_7) {
  matrix_t A;
  double det;
  double det_true = -1369800;
  double A_nums[25] = {1,  2,  3,   4, 5,  6,  7,  8,  9,  10, 11, 12, 49,
                       14, 15, 161, 7, 18, 19, 20, 64, 48, 1,  2,  3};
  s21_create_matrix(5, 5, &A);
  s21_set(A_nums, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+07);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determ_8) {
  matrix_t A;
  double det;
  double det_true = 17187;
  double A_nums[4] = {9, 2, 96, 1931};
  s21_create_matrix(2, 2, &A);
  s21_set(A_nums, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+07);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determ_9) {
  matrix_t A;
  double det;
  double det_true = 0.2;
  double A_nums[1] = {5};
  s21_create_matrix(1, 1, &A);
  s21_set(A_nums, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+07);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determ_10) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][1] = 6;
  m.matrix[0][2] = -2;
  m.matrix[0][3] = -1;
  m.matrix[0][4] = 5;
  m.matrix[1][3] = -9;
  m.matrix[1][4] = -7;
  m.matrix[2][1] = 15;
  m.matrix[2][2] = 35;
  m.matrix[3][1] = -1;
  m.matrix[3][2] = -11;
  m.matrix[3][3] = -2;
  m.matrix[3][4] = 1;
  m.matrix[4][0] = -2;
  m.matrix[4][1] = -2;
  m.matrix[4][2] = 3;
  m.matrix[4][4] = -2;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 2480, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}

// ------------------------ calc matrix -----------------------//

START_TEST(test_complem_1) {
  int result = s21_calc_complements(NULL, NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_complem_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 10, &A);
  A.rows = 0;
  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(res, 1);
  A.rows = 10;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_complem_3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(1, 2, &A);
  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_complem_4) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &C);
  A.matrix[0][0] = 123.123;
  C.matrix[0][0] = 123.123;
  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&B, &C), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_complem_5) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  double A_nums[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  double result_nums[9] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  s21_set(A_nums, &A);
  s21_set(result_nums, &C);
  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&B, &C), 1);
  ck_assert_int_eq(0, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

// ------------------------ inverse matrix -----------------------//

START_TEST(test_inverse_1) {
  int res = s21_inverse_matrix(NULL, NULL);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_inverse_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 10, &A);
  A.rows = 0;
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  A.rows = 10;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 9, &A);
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_4) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &C);
  A.matrix[0][0] = 42.12849;
  C.matrix[0][0] = 1 / 42.12849;
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_double_eq(s21_eq_matrix(&B, &C), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_inverse_5) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  double A_nums[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double result_nums[9] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  s21_set(A_nums, &A);
  s21_set(result_nums, &C);
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_double_eq(s21_eq_matrix(&B, &C), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_inverse_6) {
  matrix_t A;
  matrix_t B;
  double A_nums[25] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13,
                       14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
  s21_create_matrix(5, 5, &A);
  s21_set(A_nums, &A);
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

TCase *s21_test_all(void) {
  TCase *tc = tcase_create("meeseeks");
  tcase_add_test(tc, test_create_1);
  tcase_add_test(tc, test_create_2);
  tcase_add_test(tc, test_create_3);

  tcase_add_test(tc, test_remove_1);

  tcase_add_test(tc, test_eq_1);
  tcase_add_test(tc, test_eq_2);
  tcase_add_test(tc, test_eq_3);
  tcase_add_test(tc, test_eq_4);
  tcase_add_test(tc, test_eq_5);
  tcase_add_test(tc, test_eq_6);
  tcase_add_test(tc, test_eq_7);

  tcase_add_test(tc, test_sum_1);
  tcase_add_test(tc, test_sum_2);
  tcase_add_test(tc, test_sum_4);

  tcase_add_test(tc, test_sub_1);
  tcase_add_test(tc, test_sub_2);
  tcase_add_test(tc, test_sub_3);
  tcase_add_loop_test(tc, test_sub_4, 0, 5);

  tcase_add_loop_test(tc, test_mult_1, 0, 5);
  tcase_add_test(tc, test_mult_2);

  tcase_add_test(tc, test_mult_mat_1);
  tcase_add_test(tc, test_mult_mat_2);
  tcase_add_test(tc, test_mult_mat_3);
  tcase_add_test(tc, test_mult_mat_4);

  tcase_add_test(tc, test_transp_1);
  tcase_add_test(tc, test_transp_2);
  tcase_add_test(tc, test_transp_3);
  tcase_add_test(tc, test_transp_4);
  tcase_add_test(tc, test_transp_5);

  tcase_add_test(tc, test_determ_1);
  tcase_add_test(tc, test_determ_2);
  tcase_add_test(tc, test_determ_3);
  tcase_add_test(tc, test_determ_4);
  tcase_add_test(tc, test_determ_5);
  tcase_add_test(tc, test_determ_6);
  tcase_add_test(tc, test_determ_7);
  tcase_add_test(tc, test_determ_8);
  tcase_add_test(tc, test_determ_9);
  tcase_add_test(tc, test_determ_10);

  tcase_add_test(tc, test_complem_1);
  tcase_add_test(tc, test_complem_2);
  tcase_add_test(tc, test_complem_3);
  tcase_add_test(tc, test_complem_4);
  tcase_add_test(tc, test_complem_5);

  tcase_add_test(tc, test_inverse_1);
  tcase_add_test(tc, test_inverse_2);
  tcase_add_test(tc, test_inverse_3);
  tcase_add_test(tc, test_inverse_4);
  tcase_add_test(tc, test_inverse_5);
  tcase_add_test(tc, test_inverse_6);

  return tc;
}