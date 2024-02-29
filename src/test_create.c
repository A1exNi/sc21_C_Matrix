#include "s21_matrix.h"
#include "test_main.h"

// A[3][4]
START_TEST(create_1) {
  int rows = 3;
  int columns = 4;
  matrix_t A;
  int answer = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(answer, 0);
  s21_remove_matrix(&A);
}
END_TEST

// A[0][4]
START_TEST(create_2) {
  int rows = 0;
  int columns = 4;
  matrix_t A;
  int answer = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(answer, 1);
}
END_TEST

// A[3][0]
START_TEST(create_3) {
  int rows = 3;
  int columns = 0;
  matrix_t A;
  int answer = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(answer, 1);
}
END_TEST

// A[0][0]
START_TEST(create_4) {
  int rows = 0;
  int columns = 0;
  matrix_t A;
  int answer = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(answer, 1);
}
END_TEST

// A[-3][4]
START_TEST(create_5) {
  int rows = -3;
  int columns = 4;
  matrix_t A;
  int answer = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(answer, 1);
}
END_TEST

// A[3][-4]
START_TEST(create_6) {
  int rows = 3;
  int columns = -4;
  matrix_t A;
  int answer = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(answer, 1);
}
END_TEST

// A[-3][-4]
START_TEST(create_7) {
  int rows = -3;
  int columns = -4;
  matrix_t A;
  int answer = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(answer, 1);
}
END_TEST

Suite *create_suite(void) {
  Suite *s = suite_create("Create");
  TCase *tc_create = tcase_create("Create");
  tcase_add_test(tc_create, create_1);
  tcase_add_test(tc_create, create_2);
  tcase_add_test(tc_create, create_3);
  tcase_add_test(tc_create, create_4);
  tcase_add_test(tc_create, create_5);
  tcase_add_test(tc_create, create_6);
  tcase_add_test(tc_create, create_7);
  suite_add_tcase(s, tc_create);
  return s;
}
