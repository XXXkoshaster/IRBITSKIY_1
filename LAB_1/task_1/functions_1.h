#ifndef FUNCTIONS_1_H_
#define FUNCTIONS_1_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void print_hex(char* hex_x, int length);
long long int_pow(int base, int exp);
void print_table(int x);
void convert_to_hex(long x);

int is_multiple(char* x);
int is_prime(int x);
int sum(char* x);
long factorial(long x);

#endif