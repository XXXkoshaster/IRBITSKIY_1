#ifndef __FUNCTIONS_2_7_H__
#define __FUNCTIONS_2_7_H__

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

enum ERRORS{
    DONE,
    INVALID_INPUT,
    WRONG_PARAMETERS,
    MY_OVERFLOW,
    NULL_PTR, 
    INVALID_MEMORY,
    FILE_NOT_FOUND
};

enum ERRORS dichotomy_method(double min, double max, double eps, double (*function)(double), double* result);
double function(double x);

#endif