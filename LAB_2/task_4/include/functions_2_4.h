#ifndef __FUNCTIONS_2_4_H__
#define __FUNCTIONS_2_4_H__

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256
#define DBL_MAX 1.7976931348623158e+308

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
int is_kaprekar(int num, int base);

void heandler_status(enum ERRORS status);
double cross_product(VERTEX a, VERTEX b, VERTEX c);
int is_convex_polygon(VERTEX* vertexes, int count_coordinates);
int char_to_int(char c);
char* decimal_to_base(int decimal, int base);
int convert_to_decimal(char* str, int base);
int check_overflow(double a, double b);

#endif