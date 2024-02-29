#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int answer = 0;
  if (rows <= 0 || columns <= 0) {
    answer = 1;
  } else {
    result->matrix = calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = calloc(columns, sizeof(double));
    }
    result->rows = rows;
    result->columns = columns;
  }
  return answer;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
  free(A->matrix);
}

matrix_t s21_full_copy_matrix(matrix_t A) {
  matrix_t B;
  int not_create = s21_create_matrix(A.rows, A.columns, &B);
  if (!not_create && A.matrix)
    for (int i = 0; i < A.rows; i++)
      for (int j = 0; j < A.columns; j++) B.matrix[i][j] = A.matrix[i][j];
  return B;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int answer = SUCCESS;
  if (A->rows != B->rows || A->columns != B->columns) {
    answer = FAILURE;
  } else {
    for (int i = 0; i < A->rows && answer; i++)
      for (int j = 0; j < A->columns && answer; j++)
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-6) answer = FAILURE;
  }
  return answer;
}

int s21_sum_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result,
                       char operation) {
  int answer = 0;
  s21_create_matrix(A->rows, A->columns, result);
  if (s21_is_create(*A) && s21_is_create(*B)) {
    if (A->rows != B->rows || A->columns != B->columns) {
      answer = 2;
    } else {
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->columns; j++) {
          if (operation == '+')
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          if (operation == '-')
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
    }
  } else {
    answer = 1;
  }
  return answer;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_sum_sub_matrix(A, B, result, '+');
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_sum_sub_matrix(A, B, result, '-');
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int answer = 0;
  s21_create_matrix(A->rows, A->columns, result);
  if (s21_is_create(*A)) {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] * number;
  } else {
    answer = 1;
  }
  return answer;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int answer = 0;
  s21_create_matrix(A->rows, B->columns, result);
  if (s21_is_create(*A) && s21_is_create(*B)) {
    if (A->columns != B->rows) {
      answer = 2;
    } else {
      for (int i = 0; i < A->rows; i++)
        for (int k = 0; k < B->columns; k++)
          for (int j = 0; j < A->columns; j++)
            result->matrix[i][k] += A->matrix[i][j] * B->matrix[j][k];
    }
  } else {
    answer = 1;
  }
  return answer;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int answer = 0;
  s21_create_matrix(A->columns, A->rows, result);
  if (s21_is_create(*A)) {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[j][i] = A->matrix[i][j];
  } else {
    answer = 1;
  }
  return answer;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int answer = 0;
  s21_create_matrix(A->rows, A->columns, result);
  if (s21_is_create(*A)) {
    matrix_t R;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        s21_reduce_matrix(*A, &R, i, j);
        double det = 0;
        s21_determinant(&R, &det);
        result->matrix[i][j] = pow(-1, i + j) * det;
        s21_remove_matrix(&R);
      }
    }
  } else {
    answer = 1;
  }
  return answer;
}

// 1 - ошибка
// i, j - индекс строки и столбца
int s21_reduce_matrix(matrix_t A, matrix_t *R, int i, int j) {
  int not_create = 0;
  s21_create_matrix(A.rows - 1, A.columns - 1, R);
  if (s21_is_create(A)) {
    if (i >= A.rows || j >= A.columns) not_create = 1;
    if (!not_create) {
      int k = 0;
      for (int m = 0; m < A.rows; m++)
        if (m != i) {
          int l = 0;
          for (int n = 0; n < A.columns; n++)
            if (n != j) R->matrix[k][l++] = A.matrix[m][n];
          k++;
        }
    } else {
      not_create = 1;
    }
  } else {
    not_create = 1;
  }
  return not_create;
}

int s21_determinant(matrix_t *A, double *result) {
  int answer = 0;
  if (s21_is_create(*A)) {
    *result = 0;
    if (A->rows != A->columns) {
      answer = 2;
    } else {
      if (A->rows == 1) *result = A->matrix[0][0];
      if (A->rows == 2)
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[1][0] * A->matrix[0][1];
      if (A->rows > 2) {
        int not_create = 0;
        for (int j = 0; j < A->columns && !not_create; j++) {
          matrix_t R;
          not_create = s21_reduce_matrix(*A, &R, 0, j);
          if (!not_create) {
            double minor = 0;
            s21_determinant(&R, &minor);
            *result += pow(-1, 0 + j) * A->matrix[0][j] * minor;
          } else {
            answer = 1;
          }
          s21_remove_matrix(&R);
        }
      }
    }
  } else {
    answer = 1;
  }
  return answer;
}

int s21_is_create(matrix_t A) {
  int answer = 0;
  if (A.rows > 0 && A.columns > 0) answer = 1;
  return answer;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int answer = 0;
  s21_create_matrix(A->rows, A->columns, result);
  if (s21_is_create(*A)) {
    double det = 0;
    int not_create = s21_determinant(A, &det);
    if (!not_create && det != 0) {
      if (A->rows == 1) {
        result->matrix[0][0] = 1.0 / det;
      } else {
        matrix_t M;
        matrix_t T;
        not_create = s21_calc_complements(A, &M);
        if (!not_create) {
          not_create = s21_transpose(&M, &T);
          if (!not_create) {
            s21_remove_matrix(result);
            not_create = s21_mult_number(&T, 1.0 / det, result);
          }
        }
        if (not_create) answer = 1;
        s21_remove_matrix(&M);
        s21_remove_matrix(&T);
      }
    } else {
      answer = 1;
      if (det == 0) answer = 2;
    }
  } else {
    answer = 1;
  }
  return answer;
}
