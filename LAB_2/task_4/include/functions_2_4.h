#ifndef __FUNCTIONS_2_4_H__
#define __FUNCTIONS_2_4_H__

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define BUFFER_SIZE 256
#define EPSILON 1.e-9


enum ERRORS{
    DONE,
    INVALID_INPUT,
    WRONG_PARAMETERS,
    MY_OVERFLOW,
    NULL_PTR, 
    INVALID_MEMORY,
    FILE_NOT_FOUND
};

typedef struct {
    double x;
    double y;
} VERTEX;

enum ERRORS check_convex_polygon(int count_coordinateså, ...);
enum ERRORS method_gorner(double x, int degree, ...);
enum ERRORS find_kaprekar_number(int base, size_t count_nums, ...);
int is_kaprekar(long long num, unsigned long long square, long long base);

void heandler_status(enum ERRORS status);
double dot(const VERTEX* a, const VERTEX* b);
int char_to_int(char c);
char* decimal_to_base(long long decimal, int base);
long long convert_to_decimal(char* str, int base);
int check_overflow(long long a, int b);
int is_convex(const VERTEX* v, int n);

#endif