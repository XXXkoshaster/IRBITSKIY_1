#ifndef FUNCTIONS_7_H_
#define FUNCTIONS_7_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** read_lexemes(FILE* file, int* count);
char** merge_lexemes(char** lexemes_1, int count_1, char** lexemes_2, int count_2, int* merged_count);
void write_lexemes_r(FILE* filename, char** lexemes, int count);
int copy_lexeme(char** merged, char* lexeme, int merged_count); 
int add_lexemes(char*** lexemes, int* count, char* buffer);

void to_lower(char* lexem);
void to_base_4(char* lexem, char* result);
void to_base_8(char* lexem, char* result);
void write_lexemes_a(FILE* file, char** lexemes, int count);

#endif