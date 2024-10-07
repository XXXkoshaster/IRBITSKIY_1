#ifndef FUNCTIONS_10_H_
#define FUNCTIONS_10_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int char_to_value(char c);
void int_to_string(int value, int base, char* result);
int string_to_int(const char* str, int base);
int get_base(int* base);
void check_if_max(int* value, int* max_value, int* max_abs_value, char* max_number, char* input);
void print_answer(int answer);

#endif