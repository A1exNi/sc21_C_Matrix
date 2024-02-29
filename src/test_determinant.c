#include "s21_matrix.h"
#include "test_main.h"

// A[1][1]
START_TEST(det_1) {
  int number = 2;
  int rows = 1;
  int columns = 1;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  double result = 0;
  int answer = s21_determinant(&A, &result);
  ck_assert_int_eq(answer, 0);
  ck_assert_double_eq(result, 2);
  s21_remove_matrix(&A);
}
END_TEST

// A[2][2]
START_TEST(det_2) {
  int number = 1;
  int rows = 2;
  int columns = 2;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  double result = 0;
  int answer = s21_determinant(&A, &result);
  ck_assert_int_eq(answer, 0);
  ck_assert_double_eq(result, -2);
  s21_remove_matrix(&A);
}
END_TEST

// A[3][3]
START_TEST(det_3) {
  int number = 0;
  int rows = 3;
  int columns = 3;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  double result = 0;
  int answer = s21_determinant(&A, &result);
  ck_assert_int_eq(answer, 0);
  ck_assert_double_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

// A[4][4]
START_TEST(det_4) {
  int rows = 4;
  int columns = 4;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -9.999843472614812;
  A.matrix[0][1] = -7.369244237136675;
  A.matrix[0][2] = 5.1121064439006645;
  A.matrix[0][3] = -0.8269973615310136;
  A.matrix[1][0] = 0.655344748243385;
  A.matrix[1][1] = -5.620816273438193;
  A.matrix[1][2] = -9.059107675710278;
  A.matrix[1][3] = 3.5772943373663786;
  A.matrix[2][0] = 3.5859281167322443;
  A.matrix[2][1] = 8.693857918816551;
  A.matrix[2][2] = -2.3299584502028106;
  A.matrix[2][3] = 0.3883274413590918;
  A.matrix[3][0] = 6.619306922247311;
  A.matrix[3][1] = -9.308557789450772;
  A.matrix[3][2] = -8.930767299109496;
  A.matrix[3][3] = 0.5940038667032521;
  double result = 0;
  double orig = 1322.2995406586;
  int answer = s21_determinant(&A, &result);
  ck_assert_int_eq(answer, 0);
  ck_assert_float_eq(result, orig);
  s21_remove_matrix(&A);
}
END_TEST

// A[4][3]
START_TEST(det_5) {
  int number = 0;
  int rows = 4;
  int columns = 3;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  double result = 0;
  int answer = s21_determinant(&A, &result);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
}
END_TEST

// A[3][4] по индексам 3,3 -> answer = 1;
START_TEST(reduce_1) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  matrix_t R;
  int answer = s21_reduce_matrix(A, &R, 3, 3);
  ck_assert_int_eq(answer, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

// A[3][4] по индексам 2,4 -> answer = 1;
START_TEST(reduce_2) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  matrix_t R;
  int answer = s21_reduce_matrix(A, &R, 2, 4);
  ck_assert_int_eq(answer, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

Suite *det_suite(void) {
  Suite *s = suite_create("Determinant");
  TCase *tc_det = tcase_create("Determinant");
  tcase_add_test(tc_det, det_1);
  tcase_add_test(tc_det, det_2);
  tcase_add_test(tc_det, det_3);
  tcase_add_test(tc_det, det_4);
  tcase_add_test(tc_det, det_5);
  tcase_add_test(tc_det, reduce_1);
  tcase_add_test(tc_det, reduce_2);
  suite_add_tcase(s, tc_det);
  return s;
}
