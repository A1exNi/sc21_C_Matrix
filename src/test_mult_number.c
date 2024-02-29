#include "s21_matrix.h"
#include "test_main.h"

// C=O random
START_TEST(mult_number_1) {
  double number_m = -9.999843472614812;
  int rows = 3;
  int columns = 4;
  matrix_t A, C, O;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -7.369244237136674869;
  A.matrix[0][1] = 5.112106443900664488;
  A.matrix[0][2] = -0.826997361531013553;
  A.matrix[0][3] = 0.655344748243384956;
  A.matrix[1][0] = -5.620816273438192567;
  A.matrix[1][1] = -9.059107675710277974;
  A.matrix[1][2] = 3.577294337366378585;
  A.matrix[1][3] = 3.585928116732244320;
  A.matrix[2][0] = 8.693857918816551233;
  A.matrix[2][1] = -2.329958450202810560;
  A.matrix[2][2] = 0.388327441359091807;
  A.matrix[2][3] = 6.619306922247311320;
  s21_create_matrix(rows, columns, &O);
  O.matrix[0][0] = 73.691288882835494602841694857509237474;
  O.matrix[0][1] = -51.120264254352176062880152140294578448;
  O.matrix[0][2] = 8.269844167575577329891379385466882938;
  O.matrix[0][3] = -6.553344903034010037270103521071501976;
  O.matrix[1][0] = 56.207282922708019679448366531562978582;
  O.matrix[1][1] = 90.589658758666160157093188377284687804;
  O.matrix[1][2] = -35.77238342913510842754611590626514241;
  O.matrix[1][3] = -35.85871987137085734455409863842891872;
  O.matrix[2][0] = -86.937218361318280040640547329948936218;
  O.matrix[2][1] = 23.29921979972429761135361829393872576;
  O.matrix[2][2] = -3.883213629711925208653841479017603622;
  O.matrix[2][3] = -66.19203311966881399516907430699250072;
  int answer = s21_mult_number(&A, number_m, &C);
  ck_assert_int_eq(answer, 0);
  answer = s21_eq_matrix(&C, &O);
  ck_assert_int_eq(answer, 1);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      ck_assert_double_eq(C.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// C!=O random
START_TEST(mult_number_2) {
  double number_m = (double)rand() / RAND_MAX * (10.0 - -10.0) + -10.0;
  int rows = 3;
  int columns = 4;
  matrix_t A, C, O;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      A.matrix[i][j] =
          (double)rand() / RAND_MAX * (10.0 - -10.0) + -10.0 + 1e-6;
  s21_create_matrix(rows, columns, &O);
  O.matrix[0][0] = 73.691288882835494602841694857509237474;
  O.matrix[0][1] = -51.120264254352176062880152140294578448;
  O.matrix[0][2] = 8.269844167575577329891379385466882938;
  O.matrix[0][3] = -6.553344903034010037270103521071501976;
  O.matrix[1][0] = 56.207282922708019679448366531562978582;
  O.matrix[1][1] = 90.589658758666160157093188377284687804;
  O.matrix[1][2] = -35.77238342913510842754611590626514241;
  O.matrix[1][3] = -35.85871987137085734455409863842891872;
  O.matrix[2][0] = -86.937218361318280040640547329948936218;
  O.matrix[2][1] = 23.29921979972429761135361829393872576;
  O.matrix[2][2] = -3.883213629711925208653841479017603622;
  O.matrix[2][3] = -66.19203311966881399516907430699250072;
  int answer = s21_mult_number(&A, number_m, &C);
  ck_assert_int_eq(answer, 0);
  answer = s21_eq_matrix(&C, &O);
  ck_assert_int_eq(answer, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

Suite *mult_number_suite(void) {
  Suite *s = suite_create("Mult_number");
  TCase *tc_mult_number = tcase_create("Mult_number");
  tcase_add_test(tc_mult_number, mult_number_1);
  tcase_add_test(tc_mult_number, mult_number_2);
  suite_add_tcase(s, tc_mult_number);
  return s;
}
