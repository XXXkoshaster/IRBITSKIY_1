#ifndef FLAGS_1_H_
#define FLAGS_1_H_

#include <stdio.h>
#include "functions_1.h"

void flag_l(char* str);
void flag_r(char* str);
void flag_u(char* str);
void flag_n(char* str);
void flag_c(char** strings, int argc);
void execute_flag(char** argv, int argc);

#endif