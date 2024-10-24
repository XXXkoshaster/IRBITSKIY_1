#ifndef __FUNCTIONS_2_3_H__
#define __FUNCTIONS_2_3_H__

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

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

enum ERRORS find_substring_in_file(FILE* input_file, const char* substring, MATCH** matches, int* max_matches);
enum ERRORS get_matches(const char* substring, int count_files, ...);

enum ERRORS validate_input(const char* substring, int count_files);
enum ERRORS process_file(char* file_name, const char* substring);
void print_matches(char* file_name, MATCH* matches, int max_count_matches);
char* my_strstr(const char* src, const char* origin);
int count_lines(FILE* file);
char* resize_buffer(char* buffer, size_t* buffer_size);

#endif