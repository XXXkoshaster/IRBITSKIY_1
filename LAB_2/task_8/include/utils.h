#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum ERRORS {
    DONE,
    INVALID_INPUT,
    WRONG_PARAMETERS,
    MY_OVERFLOW,
    NULL_PTR,
    INVALID_MEMORY,
    FILE_NOT_FOUND
};

enum ERRORS char_to_int(int* value, char chr, int base);
char int_to_char(int num);
void heandler_status(enum ERRORS status);

#endif