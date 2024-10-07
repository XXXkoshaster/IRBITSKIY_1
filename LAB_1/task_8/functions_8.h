#ifndef _FUNCTIONS_8_H_
#define _FUNCTIONS_8_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int min_base(const char* num);
long long to_decimal(const char* num, int base);
long long get_file_size(FILE* file);
int validate_args(int argc, char** argv);
void process_files(FILE* in, FILE* out);

#endif