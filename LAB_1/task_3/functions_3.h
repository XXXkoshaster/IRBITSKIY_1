#ifndef FUNCTIONS_3_H_
#define FUNCTIONS_3_H_

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PERMUTATIONS_COUNT 6
#define MAX_STR_LINE 10

int solve_quadratic(double a, double b, double c, double epsilon, double* roots);
void permutations(char* a, char* b, char* c, double arr[PERMUTATIONS_COUNT][3]);
int is_unique(double arr[PERMUTATIONS_COUNT][3], int ind, double comb[3]);
int is_multiple(int a, int b);
int is_triangle(double a, double b, double c, double eps);

#endif