#include "../include/core.h"

RESPONSES read_studens(const char* filename, STUDENT** students, int count)
{
    FILE* file;
    RESPONSES response;

    response = decarator_fopen(filename, "r", &file);
    if (response.status != DONE)
        return response;
    
    *students = (STUDENT*)malloc(sizeof(STUDENT) * (count));
    if (!*students)
        return create_error_response(INVALID_ALLOCATION_MEMORY, "Invalid allocation memory");
    
    for (int i = 0; i < count; i++) {
        STUDENT* student = *students + i;
        
        fscanf(file, "%d", &student->id);
        fscanf(file, "%s", student->first_name);
        fscanf(file, "%s", student->last_name);
        fscanf(file, "%s", student->group);
        for (int j = 0; j < 5; j++)
            fscanf(file, "%hhu", student->marks + j);
    }

    fclose(file);

    return create_success_response(NULL);
}

RESPONSES search_student_by_id(STUDENT* students, int count, int id, STUDENT* result)
{
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            *result = students[i];
            return create_success_response(result);
        }
    }

    return create_error_response(INVALID_INPUT, "Invalid student id");
}

RESPONSES search_students_by_last_name(STUDENT* students, int count, const char* last_name, STUDENT** results, int* results_count)
{
    *results_count = 0;

    for (int i = 0; i < count; i++) {
        if (my_strcmp(students[i].last_name, last_name) == 0) {
            *results = (STUDENT*)realloc(*results, sizeof(STUDENT) * (*results_count + 1));
             if (!(*results))
                return create_error_response(INVALID_ALLOCATION_MEMORY, "Invalid allocation memory");
            
            (*results)[*results_count] = students[i];
            (*results_count)++;
        }
    }

    return create_success_response(NULL);
}

RESPONSES search_students_by_first_name(STUDENT* students, int count, const char*first_name, STUDENT** results, int* results_count)
{
    *results_count = 0;

    for (int i = 0; i < count; i++) {
        if (my_strcmp(students[i].first_name, first_name) == 0) {
            *results = (STUDENT*)realloc(*results, sizeof(STUDENT) * (*results_count + 1));
            if (!(*results))
                return create_error_response(INVALID_ALLOCATION_MEMORY, "Invalid allocation memory");
            
            (*results)[*results_count] = students[i];
            (*results_count)++;
        }
    }

    return create_success_response(NULL);
}

RESPONSES search_students_by_group(STUDENT* students, int count, const char* group, STUDENT** results, int* results_count)
{
    *results_count = 0;

    for (int i = 0; i < count; i++) {
        if (my_strcmp(students[i].group, group) == 0) {
            *results = (STUDENT*)realloc(*results, sizeof(STUDENT) * (*results_count + 1));
            if (!(*results))
                return create_error_response(INVALID_ALLOCATION_MEMORY, "Invalid allocation memory");
            
            (*results)[*results_count] = students[i];
            (*results_count)++;
        }
    }

    return create_success_response(NULL);
}

int compare_by_id(const void* a, const void* b) {
    return ((STUDENT*)a)->id - ((STUDENT*)b)->id;
}

int compare_by_last_name(const void* a, const void* b) {
    return my_strcmp(((STUDENT*)a)->last_name, ((STUDENT*)b)->last_name);
}

int compare_by_first_name(const void* a, const void* b) {
    return my_strcmp(((STUDENT*)a)->first_name, ((STUDENT*)b)->first_name);
}

int compare_by_group(const void* a, const void* b) {
    return my_strcmp(((STUDENT*)a)->group, ((STUDENT*)b)->group);
}

RESPONSES write_student_by_id_to_file(const char* filename, int id, STUDENT* students, int count)
{
    FILE* file;
    RESPONSES response;

    response = decarator_fopen(filename, "a", &file);
    if (response.status != DONE)
        return response;

    STUDENT result;
    response = search_student_by_id(students, count, id, &result);
    if (response.status != DONE) {
        fclose(file);
        return response;
    }

    fprintf(file, "ID: %d FIO: %s %s GROUP: %s ", result.id, result.first_name, result.last_name, result.group);
    fprintf(file, "MARKS:");
    for (int i = 0; i < 5; i++)
        fprintf(file, "%hhu ", result.marks[i]);
    fprintf(file, "\n");
    

    fclose(file);
    return create_success_response(NULL);
} 

double calculate_average_mark(STUDENT student)
{
    double sum = 0;
    for (int i = 0; i < 5; i++)
        sum += student.marks[i];
    
    return sum / 5;
}

double calculate_overall_average(STUDENT* students, int count)
{
    double sum = 0;
    for (int i = 0; i < count; i++)
        sum += calculate_average_mark(students[i]);
    
    return sum / count;
}

RESPONSES write_students_above_average_to_file(const char* filename, STUDENT* students, int count)
{
    FILE* file;
    RESPONSES response;

    response = decarator_fopen(filename, "w", &file);
    if (response.status != DONE)
        return response;

    double general_average_mark = calculate_overall_average(students, count);
    
    fprintf(file, "Average mark: %f\n", general_average_mark);

    for (int i = 0; i < count; i++) {
        double student_average_mark = calculate_average_mark(students[i]);

        if (student_average_mark > general_average_mark) {
            fprintf(file, "ID: %d FIO: %s %s GROUP: %s MARK: %f", students[i].id, students[i].first_name, students[i].last_name, students[i].group, student_average_mark);
            fprintf(file, "\n");
        }
    }

    fclose(file);
    return create_success_response(NULL);
}

RESPONSES write_students_by_sort_to_file(const char* filename, STUDENT* students, int count, const char* flag)
{
    FILE* file;
    RESPONSES response;

    if (my_strcmp(flag, "id") == 0)
        qsort(students, count, sizeof(STUDENT), compare_by_id);
    else if (my_strcmp(flag, "last_name") == 0)
        qsort(students, count, sizeof(STUDENT), compare_by_last_name);
    else if (my_strcmp(flag, "first_name") == 0)
        qsort(students, count, sizeof(STUDENT), compare_by_first_name);
    else if (my_strcmp(flag, "group") == 0)
        qsort(students, count, sizeof(STUDENT), compare_by_group);
    else 
        return create_error_response(INVALID_INPUT, "Invalid flag");

    response = decarator_fopen(filename, "w", &file);
    if (response.status != DONE)
        return response;
    
    for (int i = 0; i < count; i++) {
        double student_average_mark = calculate_average_mark(students[i]);

        fprintf(file, "ID: %d FIO: %s %s GROUP: %s MARKS: ", students[i].id, students[i].first_name, students[i].last_name, students[i].group);
        
        for (int j = 0; j < 5; j++)
            fprintf(file, "%hhu ", students[i].marks[j]);

        fprintf(file, " AVERAGE MARK: %f", student_average_mark);
        fprintf(file, "\n");
    }

    fclose(file);
    return create_success_response(NULL);
}