#include "s21_unit_tests.h"

void run_tests(void) {
  Suite *s = s21_matrix_suite();

  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(runner);
  srunner_free(runner);

  if (failed_count != 0) {
    exit(EXIT_FAILURE);
  }
}

Suite *s21_matrix_suite(void) {
  Suite *s = suite_create("s21_matrix");

  suite_add_tcase(s, s21_test_all());
  return s;
}

int main(void) {
  run_tests();
  return EXIT_SUCCESS;
}
