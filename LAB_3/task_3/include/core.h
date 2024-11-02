#ifndef __CORE_H__
#define __CORE_H__

#include <stdlib.h>

#include "responses.h"
#include "utils.h"

typedef struct {
    int id;
    char first_name[50];
    char last_name[50];
    double salary;
} EMPLOYEE;

int ascending_comparator(const void* a, const void* b);
int descending_comparator(const void* a, const void* b);
RESPONSES read_employees(const char* filename, int *count);
RESPONSES write_employees(const char* filename, EMPLOYEE* employees, int count);

#endif