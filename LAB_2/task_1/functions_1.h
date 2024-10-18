#ifndef FUCTIONS_1_H_
#define FUCTIONS_1_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char* my_strdup(char* str);
size_t length_string(char* str);
void revesed_string(char* str, char* revesed_str, size_t len);
void print_string(char* str);

void u_string(char* origin_str, char* new_str);

void n_string(char* origin_str, char* new_str, size_t len_str);

void c_string(char** result, char** strings, int argc);
char** allocate_lexemes(unsigned int count_strings);
void initialize_random(char* seed);
void concatenate_random_strings(char** new_string, char** lexemes, unsigned int count_strings);
void free_lexemes(char** lexemes, unsigned int count_strings);
void create_lexemes(char** argv, char** lexemes, int argc);

char* concatenate_strings(char* dest, const char* strc);

#endif