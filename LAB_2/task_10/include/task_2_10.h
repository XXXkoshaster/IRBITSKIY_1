#ifndef __TASK_2_10_H__
#define __TASK_2_10_H__

#include "utils.h"

double calculation_of_polynomial(double *coefs, double a, unsigned int max_degree);
enum ERRORS decomposition_of_a_polynomial(double a, double **coefs, unsigned int degree, ...);

#endif