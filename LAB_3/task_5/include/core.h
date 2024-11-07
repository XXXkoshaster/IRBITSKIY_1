#ifndef __CORE_H__
#define __CORE_H__

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "responses.h"
#include "utils.h"

typedef struct {
    int id;
    char first_name[50];
    char last_name[50];
    char group[50];
    unsigned char marks[5];
} STUDENT;

RESPONSES read_studens(const char* filename, STUDENT** students, int count);
RESPONSES search_student_by_id(STUDENT* students, int count, int id, STUDENT* result);

RESPONSES search_students_by_last_name(
                                        STUDENT* students,
                                        int count, 
                                        const char* last_name,
                                        STUDENT** results,
                                        int* results_count
                                    );

RESPONSES search_students_by_first_name(
                                        STUDENT* students,
                                        int count, 
                                        const char* first_name,
                                        STUDENT** results,
                                        int* results_count
                                    );

RESPONSES search_students_by_group(
                                        STUDENT* students,
                                        int count, 
                                        const char* group,
                                        STUDENT** results,
                                        int* results_count
                                    );

int compare_by_id(const void* a, const void* b);
int compare_by_last_name(const void* a, const void* b);
int compare_by_first_name(const void* a, const void* b);
int compare_by_group(const void* a, const void* b);

RESPONSES write_student_by_id_to_file(const char* filename, int id, STUDENT* students, int count);
RESPONSES write_students_above_average_to_file(const char* filename, STUDENT* students, int count);    
RESPONSES write_students_by_sort_to_file(const char* filename, STUDENT* students, int count, const char* flag);


double calculate_average_mark(STUDENT student);
double calculate_overall_average(STUDENT* students, int count);

#endif