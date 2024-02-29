#include "s21_matrix.h"
#include "test_main.h"

// A[3][4] -> C[4][3]
START_TEST(transpose_1) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A, C, O;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  s21_transpose(&A, &C);
  s21_create_matrix(columns, rows, &O);
  O.matrix[0][0] = 0;
  O.matrix[0][1] = 4;
  O.matrix[0][2] = 8;
  O.matrix[1][0] = 1;
  O.matrix[1][1] = 5;
  O.matrix[1][2] = 9;
  O.matrix[2][0] = 2;
  O.matrix[2][1] = 6;
  O.matrix[2][2] = 10;
  O.matrix[3][0] = 3;
  O.matrix[3][1] = 7;
  O.matrix[3][2] = 11;
  int answer = s21_eq_matrix(&C, &O);
  ck_assert_int_eq(answer, 1);
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++)
      ck_assert_double_eq(C.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// A[4][3] -> C[3][4]
START_TEST(transpose_2) {
  int number = 0;
  int rows = 4;
  int columns = 3;
  matrix_t A, C, O;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  s21_transpose(&A, &C);
  s21_create_matrix(columns, rows, &O);
  O.matrix[0][0] = 0;
  O.matrix[0][1] = 3;
  O.matrix[0][2] = 6;
  O.matrix[0][3] = 9;
  O.matrix[1][0] = 1;
  O.matrix[1][1] = 4;
  O.matrix[1][2] = 7;
  O.matrix[1][3] = 10;
  O.matrix[2][0] = 2;
  O.matrix[2][1] = 5;
  O.matrix[2][2] = 8;
  O.matrix[2][3] = 11;
  int answer = s21_eq_matrix(&C, &O);
  ck_assert_int_eq(answer, 1);
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++)
      ck_assert_double_eq(C.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// A[4][4] -> C[4][4]
START_TEST(transpose_3) {
  int number = 0;
  int rows = 4;
  int columns = 4;
  matrix_t A, C, O;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  s21_transpose(&A, &C);
  s21_create_matrix(columns, rows, &O);
  O.matrix[0][0] = 0;
  O.matrix[0][1] = 4;
  O.matrix[0][2] = 8;
  O.matrix[0][3] = 12;
  O.matrix[1][0] = 1;
  O.matrix[1][1] = 5;
  O.matrix[1][2] = 9;
  O.matrix[1][3] = 13;
  O.matrix[2][0] = 2;
  O.matrix[2][1] = 6;
  O.matrix[2][2] = 10;
  O.matrix[2][3] = 14;
  O.matrix[3][0] = 3;
  O.matrix[3][1] = 7;
  O.matrix[3][2] = 11;
  O.matrix[3][3] = 15;
  int answer = s21_eq_matrix(&C, &O);
  ck_assert_int_eq(answer, 1);
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++)
      ck_assert_double_eq(C.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

Suite *transpose_suite(void) {
  Suite *s = suite_create("Transpose");
  TCase *tc_trans = tcase_create("Transpose");
  tcase_add_test(tc_trans, transpose_1);
  tcase_add_test(tc_trans, transpose_2);
  tcase_add_test(tc_trans, transpose_3);
  suite_add_tcase(s, tc_trans);
  return s;
}
