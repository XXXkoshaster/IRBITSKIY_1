#ifndef FUCTIONS_1_H_
#define FUCTIONS_1_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

size_t length_string(char* str);
void revesed_string(char* str, char* revesed_str, size_t len);
void print_string(char* str);
void u_string(char* origin_str, char* new_str);
void n_string(char* origin_str, char* new_str, size_t len_str);
void c_string(char* result, char** strings, int argc);
void create_lexemes(char** argv, char** lexemes, int argc);
void concatenate_strings(char* result, char* f_string, char* s_string);

#endif