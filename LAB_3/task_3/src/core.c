#include "../include/core.h"

int ascending_comparator(const void* a, const void* b)
{
    EMPLOYEE* emp_1 = (EMPLOYEE *) a;
    EMPLOYEE* emp_2 = (EMPLOYEE *) b;

    if (emp_1->salary != emp_2->salary)
        return (emp_1->salary > emp_2->salary) - (emp_1->salary < emp_2->salary);
    
    int last_name_cmp = my_strcmp(emp_1->last_name, emp_2->last_name);
    if (last_name_cmp != 0)
        return last_name_cmp;

    int first_name_cmp = my_strcmp(emp_1->first_name, emp_2->first_name);
    if (first_name_cmp != 0)
        return first_name_cmp;
    
    return (emp_1->id > emp_2->id) - (emp_1->id < emp_2->id);
}

int descending_comparator(const void* a, const void* b)
{
    return ascending_comparator(b, a);
}

RESPONSES read_employees(const char* filename, int* count)
{
    FILE* file = fopen(filename, "r");  
    if (!file)
        return create_error_response(FILE_NOT_FOUND, "File not found");
    
    EMPLOYEE* employees = malloc(sizeof(EMPLOYEE));
    if (!employees)
        return create_error_response(INVALID_ALLOCATION_MEMORY, "Invalid allocation array");

    EMPLOYEE tmp;

    while (fscanf(file, "%d %49s %49s %lf", &tmp.id, tmp.first_name, tmp.last_name, &tmp.salary) == 4) {
        employees = realloc(employees, (*count + 1) * sizeof(EMPLOYEE));
        if (!employees) {
            free(employees);
            return create_error_response(INVALID_ALLOCATION_MEMORY, "Invalid allocation array");
        }

        employees[*count] = tmp;
        (*count)++;
    }

    fclose(file);

    return create_success_response(employees);
}

RESPONSES write_employees(const char* filename, EMPLOYEE* employees, int count)
{
    FILE* file = fopen(filename, "w");  
    if (!file)
        return create_error_response(FILE_WRITE_ERROR, "File write error");

    for (int i = 0; i < count; i++ )
        fprintf(file, "%d %s %s %.2lf\n", employees[i].id, employees[i].first_name, employees[i].last_name, employees[i].salary);
    
    fclose(file);

    return create_success_response(NULL);
}