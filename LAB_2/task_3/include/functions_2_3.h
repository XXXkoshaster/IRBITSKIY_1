#ifndef __FUNCTIONS_2_3_H__
#define __FUNCTIONS_2_3_H__

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

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
    int char_position;
} MATCH;

typedef struct {
    enum ERRORS status;
    MATCH* match_array; // массив вхождений
    int match_count; 
    char* file_name;
    int processed_file_count; // кол-во обработанных файлов
} RESULT;

RESULT* get_matches(const char* substring, ...);
void create_arr_prefix(int* arr_prefix, const char* image);
enum ERRORS find_substr(char *substr, const char* file_name, int arr_prefix[], int substr_len, MATCH **matches);
int count_lines(const char *str);
int my_strlen(const char* str);
char* replace_tabs_with_spaces(const char* str, int tab_size);

#endif