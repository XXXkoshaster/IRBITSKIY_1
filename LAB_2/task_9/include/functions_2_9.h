#ifndef __FUNCTIONS_2_9_H__
#define __FUNCTIONS_2_9_H__

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


enum ERRORS check_finite_representation(int base, int count_fractions, ...);
enum ERRORS has_finite_representation(int* flag, int numerator, int denominator, int base);
int gcd(int a, int b);

#endif