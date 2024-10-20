#ifndef __FUNCTIONS_2_3_H__
#define __FUNCTIONS_2_3_H__

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

typedef struct {
    int line_number;
    int position;
} MATCH;

enum ERRORS find_substring_in_file(FILE* input_file, const char* substring, MATCH* matches);
enum ERRORS get_matches(const char* substring, int count_files, ...);

char* my_strstr(const char* src, const char* origin);
int count_lines(FILE* file);

#endif