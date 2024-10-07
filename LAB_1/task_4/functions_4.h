#ifndef FUNCTIONS_4_H_
#define FUNCTIONS_4_H_

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void del_digits(FILE* in_file, FILE* out_file); 
void count_lat_letters(FILE* in_file, FILE* out_file);
void count_other_letters(FILE* in_file, FILE* out_file);
void convert_to_ascii(FILE* in_file, FILE* out_file);
const char* generate_out_file(const char* in_file);

#endif