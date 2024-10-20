#ifndef FUNCTIONS_2_H
#define FUNCTIONS_2_H

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>

enum errors{
    DONE,
    INVALID_INPUT,
    WRONG_PARAMETERS,
    MY_OVERFLOW,
    NULL_PTR, 
    INVALID_MEMORY
};

enum errors geom_average(double *result, int count, ...);
int check_overflow(double* number);
enum errors fast_pow(double* result, double base, int power);

#endif