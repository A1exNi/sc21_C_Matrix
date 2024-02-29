#include "s21_matrix.h"
#include "test_main.h"

START_TEST(complements_1) {
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
  O.matrix[0][0] = -287.52218386508594;
  O.matrix[0][1] = 62.0154831847248;
  O.matrix[0][2] = -321.99530318472296;
  O.matrix[0][3] = -665.3034690140292;
  O.matrix[1][0] = -21.909909333060277;
  O.matrix[1][1] = -4.858737813708748;
  O.matrix[1][2] = 15.83710313580812;
  O.matrix[1][3] = 406.1220290167821;
  O.matrix[2][0] = -320.7150121781577;
  O.matrix[2][1] = 191.3543288557128;
  O.matrix[2][2] = -496.95539497628556;
  O.matrix[2][3] = -899.0666423454255;
  O.matrix[3][0] = -58.68556539466871;
  O.matrix[3][1] = -9.495494891654378;
  O.matrix[3][2] = -218.78953288252893;
  O.matrix[3][3] = -558.2294615722393;
  matrix_t M;
  s21_calc_complements(&A, &M);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      ck_assert_float_eq(M.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&M);
  s21_remove_matrix(&O);
}
END_TEST

START_TEST(complements_2) {
  int rows = 3;
  int columns = 3;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  matrix_t O;
  s21_create_matrix(rows, columns, &O);
  O.matrix[0][0] = 0;
  O.matrix[0][1] = 10;
  O.matrix[0][2] = -20;
  O.matrix[1][0] = 4;
  O.matrix[1][1] = -14;
  O.matrix[1][2] = 8;
  O.matrix[2][0] = -8;
  O.matrix[2][1] = -2;
  O.matrix[2][2] = 4;
  matrix_t M = {0};
  s21_calc_complements(&A, &M);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      ck_assert_double_eq(M.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&M);
  s21_remove_matrix(&O);
}
END_TEST

Suite *comp_suite(void) {
  Suite *s = suite_create("Complements");
  TCase *tc_comp = tcase_create("Complements");
  tcase_add_test(tc_comp, complements_1);
  tcase_add_test(tc_comp, complements_2);
  suite_add_tcase(s, tc_comp);
  return s;
}
