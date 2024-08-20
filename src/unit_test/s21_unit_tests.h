#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"

Suite *s21_matrix_suite(void);
void run_tests(void);

TCase *s21_test_all(void);
#endif
