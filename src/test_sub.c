#include "s21_matrix.h"
#include "test_main.h"

// A[3][4] B[3][4]
START_TEST(sub_1) {
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
      O.matrix[i][j] = number - number - 1;
    }
  int answer = s21_sub_matrix(&A, &B, &C);
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
START_TEST(sub_2) {
  int rows = 3;
  int columns = 4;
  matrix_t A, B, C, O;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns + 1, &B);
  s21_create_matrix(rows, columns, &O);
  int answer = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// A[3][4] B[4][4]
START_TEST(sub_3) {
  int rows = 3;
  int columns = 4;
  matrix_t A, B, C, O;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows + 1, columns, &B);
  s21_create_matrix(rows, columns, &O);
  int answer = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// A[3][4] B[4][5]
START_TEST(sub_4) {
  int rows = 3;
  int columns = 4;
  matrix_t A, B, C, O;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows + 1, columns + 1, &B);
  s21_create_matrix(rows, columns, &O);
  int answer = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// C=O
START_TEST(sub_5) {
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
      O.matrix[i][j] = (number - 1) - (number + 1e-14);
    }
  int answer = s21_sub_matrix(&A, &B, &C);
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

// C=O
START_TEST(sub_6) {
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
      O.matrix[i][j] = (number - 1) - (number + 1e-15);
    }
  int answer = s21_sub_matrix(&A, &B, &C);
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

// C=O 1.1e-15
START_TEST(sub_7) {
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
      O.matrix[i][j] = (number - 1) - (number + 1e-15);
    }
  int answer = s21_sub_matrix(&A, &B, &C);
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

// C!=O 1.1e-14
START_TEST(sub_8) {
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
      O.matrix[i][j] = (number - 1) - (number + 1e-14);
    }
  int answer = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 0);
  answer = s21_eq_matrix(&C, &O);
  ck_assert_int_eq(answer, 1);
  ck_assert_double_ne(C.matrix[0][0], O.matrix[0][0]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// C!=O 1.1e-14
START_TEST(sub_9) {
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
      O.matrix[i][j] = (number - 1) - (number + 1.1e-14);
    }
  int answer = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 0);
  answer = s21_eq_matrix(&C, &O);
  ck_assert_int_eq(answer, 1);
  ck_assert_ldouble_ne(C.matrix[0][0], O.matrix[0][0]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// C=O random
START_TEST(sub_10) {
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
      O.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  int answer = s21_sub_matrix(&A, &B, &C);
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

Suite *sub_suite(void) {
  Suite *s = suite_create("Sub");
  TCase *tc_sub = tcase_create("Sub");
  tcase_add_test(tc_sub, sub_1);
  tcase_add_test(tc_sub, sub_2);
  tcase_add_test(tc_sub, sub_3);
  tcase_add_test(tc_sub, sub_4);
  tcase_add_test(tc_sub, sub_5);
  tcase_add_test(tc_sub, sub_6);
  tcase_add_test(tc_sub, sub_7);
  tcase_add_test(tc_sub, sub_8);
  tcase_add_test(tc_sub, sub_9);
  tcase_add_test(tc_sub, sub_10);
  suite_add_tcase(s, tc_sub);
  return s;
}
