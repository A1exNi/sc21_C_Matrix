#include "s21_matrix.h"
#include "test_main.h"

START_TEST(inverse_1) {
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
  matrix_t O;
  s21_create_matrix(rows, columns, &O);
  O.matrix[0][0] = -0.21744104;
  O.matrix[0][1] = -0.016569550740482955;
  O.matrix[0][2] = -0.24254339;
  O.matrix[0][3] = -0.04438144579966978;
  O.matrix[1][0] = 0.04689972375989467;
  O.matrix[1][1] = -0.003674460789185998;
  O.matrix[1][2] = 0.1447133;
  O.matrix[1][3] = -0.007181046804965847;
  O.matrix[2][0] = -0.24351162;
  O.matrix[2][1] = 0.011976940661962183;
  O.matrix[2][2] = -0.37582664;
  O.matrix[2][3] = -0.1654614;
  O.matrix[3][0] = -0.50314127;
  O.matrix[3][1] = 0.3071331544246765;
  O.matrix[3][2] = -0.67992661;
  O.matrix[3][3] = -0.42216566;
  matrix_t I;
  s21_inverse_matrix(&A, &I);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      ck_assert_float_eq(I.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&I);
  s21_remove_matrix(&O);
}
END_TEST

START_TEST(inverse_2) {
  int rows = 3;
  int columns = 3;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  matrix_t O;
  s21_create_matrix(rows, columns, &O);
  O.matrix[0][0] = 1;
  O.matrix[0][1] = -1;
  O.matrix[0][2] = 1;
  O.matrix[1][0] = -38;
  O.matrix[1][1] = 41;
  O.matrix[1][2] = -34;
  O.matrix[2][0] = 27;
  O.matrix[2][1] = -29;
  O.matrix[2][2] = 24;
  matrix_t I;
  s21_inverse_matrix(&A, &I);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      ck_assert_int_eq(I.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&I);
  s21_remove_matrix(&O);
}
END_TEST

START_TEST(inverse_3) {
  int rows = 2;
  int columns = 3;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      A.matrix[i][j] = (double)rand() / RAND_MAX * (10.0 - -10.0) + -10.0;
  matrix_t I;
  int answer = s21_inverse_matrix(&A, &I);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&I);
}
END_TEST

START_TEST(inverse_4) {
  int rows = 3;
  int columns = 3;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = -2;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  matrix_t I;
  int answer = s21_inverse_matrix(&A, &I);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&I);
}
END_TEST

START_TEST(inverse_5) {
  int rows = 1;
  int columns = 1;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 5;
  matrix_t I;
  int answer = s21_inverse_matrix(&A, &I);
  ck_assert_int_eq(answer, 0);
  ck_assert_float_eq(I.matrix[0][0], 1.0 / 5.0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&I);
}
END_TEST

Suite *inverse_suite(void) {
  Suite *s = suite_create("Inverse");
  TCase *tc_inverse = tcase_create("Inverse");
  tcase_add_test(tc_inverse, inverse_1);
  tcase_add_test(tc_inverse, inverse_2);
  tcase_add_test(tc_inverse, inverse_3);
  tcase_add_test(tc_inverse, inverse_4);
  tcase_add_test(tc_inverse, inverse_5);
  suite_add_tcase(s, tc_inverse);
  return s;
}
