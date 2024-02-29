#include "s21_matrix.h"
#include "test_main.h"

// A[3][4] * B[4][5]
START_TEST(mult_matrix_1) {
  int rows = 3;
  int columns = 4;
  int rows2 = 4;
  int columns2 = 5;
  matrix_t A, B, C, O;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -9.999843472614811546;
  A.matrix[0][1] = -7.369244237136674869;
  A.matrix[0][2] = 5.112106443900664488;
  A.matrix[0][3] = -0.826997361531013553;
  A.matrix[1][0] = 0.655344748243384956;
  A.matrix[1][1] = -5.620816273438192567;
  A.matrix[1][2] = -9.059107675710277974;
  A.matrix[1][3] = 3.577294337366378585;
  A.matrix[2][0] = 3.585928116732244320;
  A.matrix[2][1] = 8.693857918816551233;
  A.matrix[2][2] = -2.329958450202810560;
  A.matrix[2][3] = 0.388327441359091807;
  s21_create_matrix(rows2, columns2, &B);
  B.matrix[0][0] = 6.619306922247311320;
  B.matrix[0][1] = -9.308557789450771836;
  B.matrix[0][2] = -8.930767299109495738;
  B.matrix[0][3] = 0.594003866703252115;
  B.matrix[0][4] = 3.422987681544846339;
  B.matrix[1][0] = -9.846036275777050761;
  B.matrix[1][1] = -2.331686984902101578;
  B.matrix[1][2] = -8.663155249628776033;
  B.matrix[1][3] = -1.650280510843861848;
  B.matrix[1][4] = 3.735454247209922585;
  B.matrix[2][0] = 1.779532857136583601;
  B.matrix[2][1] = 8.608729894556446993;
  B.matrix[2][2] = 6.923337810171460660;
  B.matrix[2][3] = 0.538575551723397439;
  B.matrix[2][4] = -8.160702184848814156;
  B.matrix[3][0] = 3.078379245977094669;
  B.matrix[3][1] = -1.680012862980371224;
  B.matrix[3][2] = 4.023811888892117494;
  B.matrix[3][3] = 8.206416609793162564;
  B.matrix[3][4] = 5.243960793709362633;
  s21_create_matrix(rows, columns2, &O);
  O.matrix[0][0] = 12.91716283612586708908212928823433692;
  O.matrix[0][1] = 155.665001499378692890643732986346945194;
  O.matrix[0][2] = 185.212339997456825448193497227269451523;
  O.matrix[0][3] = 2.187945119603927581527655534279794462;
  O.matrix[0][4] = -107.811935674766153979519959965153703636;
  O.matrix[1][0] = 54.571977835891659110367706816227754398;
  O.matrix[1][1] = -76.991641879070050848930993620962598712;
  O.matrix[1][2] = -5.483630653718418805162987774507007667;
  O.matrix[1][3] = 34.14295461928445916225538340893824911;
  O.matrix[1][4] = 73.934806033658200438502876758608464638;
  O.matrix[2][0] = -64.81450012112804629548983049296078559;
  O.matrix[2][1] = -74.361552521177967684075880112951725042;
  O.matrix[2][2] = -121.909863289885783871624436155737504791;
  O.matrix[2][3] = -10.285331013412507237365060284083964476;
  O.matrix[2][4] = 65.800567150748268875922968135638376976;
  int answer = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 0);
  answer = s21_eq_matrix(&C, &O);
  ck_assert_int_eq(answer, 1);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns2; j++)
      ck_assert_float_eq(C.matrix[i][j], O.matrix[i][j]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

// A[3][4] * B[3][5] answer = 2
START_TEST(mult_matrix_2) {
  int rows = 3;
  int columns = 4;
  int rows2 = 3;
  int columns2 = 5;
  matrix_t A, B, C, O;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      A.matrix[i][j] = (double)rand() / RAND_MAX * (10.0 - -10.0) + -10.0;
  s21_create_matrix(rows2, columns2, &B);
  for (int i = 0; i < rows2; i++)
    for (int j = 0; j < columns2; j++)
      B.matrix[i][j] = (double)rand() / RAND_MAX * (10.0 - -10.0) + -10.0;
  s21_create_matrix(rows, columns2, &O);
  int answer = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&O);
}
END_TEST

Suite *mult_matrix_suite(void) {
  Suite *s = suite_create("Mult_matrix");
  TCase *tc_mult_matrix = tcase_create("Mut_matrix");
  tcase_add_test(tc_mult_matrix, mult_matrix_1);
  tcase_add_test(tc_mult_matrix, mult_matrix_2);
  suite_add_tcase(s, tc_mult_matrix);
  return s;
}
