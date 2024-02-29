#ifndef TEST_MAIN_H
#define TEST_MAIN_H

#include <check.h>
#include <stdlib.h>

Suite *create_suite(void);
Suite *transpose_suite(void);
Suite *sum_suite(void);
Suite *mult_number_suite(void);
Suite *mult_matrix_suite(void);
Suite *inverse_suite(void);
Suite *eq_suite(void);
Suite *det_suite(void);
Suite *sub_suite(void);
Suite *comp_suite(void);

#endif  // TEST_MAIN_H
