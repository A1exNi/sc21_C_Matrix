#include "s21_matrix.h"
#include "test_main.h"

// A == B
START_TEST(equal_1) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  matrix_t B = s21_full_copy_matrix(A);
  int answer = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(answer, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// A[3][4] != B[3][4]
START_TEST(equal_2) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  matrix_t B = s21_full_copy_matrix(A);
  B.matrix[0][3] += 1e-14;
  int answer = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(answer, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// A[3][4] != B[3][4]
START_TEST(equal_3) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  matrix_t B = s21_full_copy_matrix(A);
  B.matrix[2][3] += 1e-14;
  int answer = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(answer, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// A[3][4] != B[3][4]
START_TEST(equal_4) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  matrix_t B = s21_full_copy_matrix(A);
  B.matrix[2][3] += 9e-14;
  int answer = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(answer, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// A[3][4] == B[3][4]
START_TEST(equal_5) {
  double number = 0.0;
  int rows = 3;
  int columns = 4;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  matrix_t B = s21_full_copy_matrix(A);
  B.matrix[2][3] += 1e-15;
  int answer = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(answer, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// A[3][4] != B[4][4]
START_TEST(equal_6) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  matrix_t B;
  s21_create_matrix(rows + 1, columns, &B);
  for (int i = 0; i < rows + 1; i++)
    for (int j = 0; j < columns; j++) B.matrix[i][j] = number++;
  int answer = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(answer, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// A[3][4] != B[3][5]
START_TEST(equal_7) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  matrix_t B;
  s21_create_matrix(rows, columns + 1, &B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns + 1; j++) B.matrix[i][j] = number++;
  int answer = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(answer, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// A[3][4] != B[4][5]
START_TEST(equal_8) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  matrix_t B;
  s21_create_matrix(rows + 1, columns + 1, &B);
  for (int i = 0; i < rows + 1; i++)
    for (int j = 0; j < columns + 1; j++) B.matrix[i][j] = number++;
  int answer = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(answer, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// A[3][4] != B[3][4]
START_TEST(equal_9) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = number++;
  matrix_t B = s21_full_copy_matrix(A);
  B.matrix[0][3] *= -1;
  int answer = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(answer, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// -A == -B
START_TEST(equal_10) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A.matrix[i][j] = -1 * number++;
  matrix_t B = s21_full_copy_matrix(A);
  int answer = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(answer, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *eq_suite(void) {
  Suite *s = suite_create("Equal");
  TCase *tc_equal = tcase_create("Equal");
  tcase_add_test(tc_equal, equal_1);
  tcase_add_test(tc_equal, equal_2);
  tcase_add_test(tc_equal, equal_3);
  tcase_add_test(tc_equal, equal_4);
  tcase_add_test(tc_equal, equal_5);
  tcase_add_test(tc_equal, equal_6);
  tcase_add_test(tc_equal, equal_7);
  tcase_add_test(tc_equal, equal_8);
  tcase_add_test(tc_equal, equal_9);
  tcase_add_test(tc_equal, equal_10);
  suite_add_tcase(s, tc_equal);
  return s;
}
