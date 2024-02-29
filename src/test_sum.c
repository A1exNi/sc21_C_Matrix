#include "s21_matrix.h"
#include "test_main.h"

// A[3][4] B[3][4]
START_TEST(sum_1) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A, B, C, O;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &O);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = number++;
      B.matrix[i][j] = number;
      O.matrix[i][j] = number + number - 1;
    }
  int answer = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 0);
  answer = s21_eq_matrix(&C, &O);
  ck_assert_int_eq(answer, 1);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      ck_assert_double_eq(C.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// A[3][4] B[3][5]
START_TEST(sum_2) {
  int rows = 3;
  int columns = 4;
  matrix_t A, B, C, O;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns + 1, &B);
  s21_create_matrix(rows, columns, &O);
  int answer = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// A[3][4] B[4][4]
START_TEST(sum_3) {
  int rows = 3;
  int columns = 4;
  matrix_t A, B, C, O;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows + 1, columns, &B);
  s21_create_matrix(rows, columns, &O);
  int answer = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// A[3][4] B[4][5]
START_TEST(sum_4) {
  int rows = 3;
  int columns = 4;
  matrix_t A, B, C, O;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows + 1, columns + 1, &B);
  s21_create_matrix(rows, columns, &O);
  int answer = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// C=O
START_TEST(sum_5) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A, B, C, O;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &O);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = number++;
      B.matrix[i][j] = number + 1e-14;
      O.matrix[i][j] = number + number - 1 + 1e-14;
    }
  int answer = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 0);
  answer = s21_eq_matrix(&C, &O);
  ck_assert_int_eq(answer, 1);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      ck_assert_float_eq(C.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// C=O
START_TEST(sum_6) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A, B, C, O;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &O);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = number++;
      B.matrix[i][j] = number + 1e-15;
      O.matrix[i][j] = number + number - 1 + 1e-15;
    }
  int answer = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 0);
  answer = s21_eq_matrix(&C, &O);
  ck_assert_int_eq(answer, 1);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      ck_assert_float_eq(C.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// C=O 1.1e-15
START_TEST(sum_7) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A, B, C, O;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &O);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = number++;
      B.matrix[i][j] = number + 1.1e-15;
      O.matrix[i][j] = number + number - 1 + 1e-15;
    }
  int answer = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 0);
  answer = s21_eq_matrix(&C, &O);
  ck_assert_int_eq(answer, 1);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      ck_assert_float_eq(C.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// C!=O 1.1e-14
START_TEST(sum_8) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A, B, C, O;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &O);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = number++;
      B.matrix[i][j] = number + 1.1e-14;
      O.matrix[i][j] = number + number - 1 + 1e-14;
    }
  int answer = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 0);
  answer = s21_eq_matrix(&C, &O);
  ck_assert_int_eq(answer, 1);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      ck_assert_float_eq(C.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// C!=O 1.1e-14
START_TEST(sum_9) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A, B, C, O;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &O);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = number++;
      B.matrix[i][j] = number + 1e-14;
      O.matrix[i][j] = number + number - 1 + 1.1e-14;
    }
  int answer = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 0);
  answer = s21_eq_matrix(&C, &O);
  ck_assert_int_eq(answer, 1);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      ck_assert_float_eq(C.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// C=O random
START_TEST(sum_10) {
  int rows = 3;
  int columns = 4;
  matrix_t A, B, C, O;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &O);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)rand() / RAND_MAX * (10.0 - -10.0) + -10.0;
      B.matrix[i][j] = (double)rand() / RAND_MAX * (10.0 - -10.0) + -10.0;
      O.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  int answer = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 0);
  answer = s21_eq_matrix(&C, &O);
  ck_assert_int_eq(answer, 1);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      ck_assert_float_eq(C.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

Suite *sum_suite(void) {
  Suite *s = suite_create("Sum");
  TCase *tc_sum = tcase_create("Sum");
  tcase_add_test(tc_sum, sum_1);
  tcase_add_test(tc_sum, sum_2);
  tcase_add_test(tc_sum, sum_3);
  tcase_add_test(tc_sum, sum_4);
  tcase_add_test(tc_sum, sum_5);
  tcase_add_test(tc_sum, sum_6);
  tcase_add_test(tc_sum, sum_7);
  tcase_add_test(tc_sum, sum_8);
  tcase_add_test(tc_sum, sum_9);
  tcase_add_test(tc_sum, sum_10);
  suite_add_tcase(s, tc_sum);
  return s;
}
