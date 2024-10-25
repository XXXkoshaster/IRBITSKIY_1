#ifndef __TASK_2_10_H__
#define __TASK_2_10_H__

#include "utils.h"

enum ERRORS coef_calculation(double x, double *coefs, int count, double *res);
enum ERRORS calc_differ(double *coefs, int count, int iter);
enum ERRORS decomposition_of_a_polynomial(int count, double eps, double x, double **result, ...);
void print_coefficients(double *coefs, int count);

#endif