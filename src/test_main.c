#include "test_main.h"

int main(void) {
  int no_failed = 0;
  SRunner *runner;
  runner = srunner_create(create_suite());
  srunner_add_suite(runner, transpose_suite());
  srunner_add_suite(runner, sum_suite());
  srunner_add_suite(runner, mult_number_suite());
  srunner_add_suite(runner, mult_matrix_suite());
  srunner_add_suite(runner, inverse_suite());
  srunner_add_suite(runner, eq_suite());
  srunner_add_suite(runner, det_suite());
  srunner_add_suite(runner, sub_suite());
  srunner_add_suite(runner, comp_suite());
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
