#ifndef FUNCTIONS_7_H_
#define FUNCTIONS_7_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** read_lexemes(FILE* file, int* count);
char** merge_lexemes(char** lexemes_1, int count_1, char** lexemes_2, int count_2, int* merged_count);
void write_lexemes(FILE* filename, char** lexemes, int count);

#endif