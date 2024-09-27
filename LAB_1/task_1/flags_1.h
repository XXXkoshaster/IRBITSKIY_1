#ifndef FLAGS_1_H_
#define FLAGS_1_H_

#include "math_functions.h"

void flag_h(char* x);
void flag_p(char* x);
void flag_a(char* x);
void flag_f(char* x);
void flag_s(char* x);
void flag_e(char* x);

void print_hex(char* hex_x, int length);
void print_table(int x);
void convert_to_hex(long x);

void execute_flag(char* flag, char* x);

#endif