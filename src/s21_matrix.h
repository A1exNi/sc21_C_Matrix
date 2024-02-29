#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows, columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result,
                       char operation);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int s21_reduce_matrix(matrix_t A, matrix_t *R, int i, int j);
void s21_print_matrix(matrix_t A);
matrix_t s21_full_copy_matrix(matrix_t A);
int s21_is_create(matrix_t A);

#endif  // S21_MATRIX_H
