#ifndef _FUNCTIONS_6_H_
#define _FUNCTIONS_6_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double expression_a(double x);
double expression_b(double x);
double expression_c(double x);
double expression_d(double x);

double trapezoidal(double (*f)(double), double a, double b, int n);
double integral(double epsilon, double (*f)(double), double a, double b);

#endif