#ifndef FUNCTIONS_9_H_
#define FUNCTIONS_9_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void fillArray(long *array, long size, long min, long max);
void first_task(char* a, char* b);
int is_number(char* symbol);
void swap(long*a , long*b);
void find_min_and_max(long* array, long size);
void printf_array(long* array, long size);

int second_task();
long bin_search(long origin, long* arr, long size);
long get_random_number(long a, long b);

#endif