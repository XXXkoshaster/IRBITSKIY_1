#include "../include/core.h"

RESPONSES read_from_file(const char* filename, p_unidirectional_list list)
{
    FILE* file = fopen(filename, "r");
    if (!file)
    {
        return create_error_response(FILE_NOT_FOUND, "File not found");
    }

    LIVER liver;
    while (fscanf(file, "%s %s %s %d %d %d %c %lf", 
                                                    liver.surname, 
                                                    liver.name, 
                                                    liver.patronymic, 
                                                    &liver.day, 
                                                    &liver.month,
                                                    &liver.year,
                                                    &liver.gender,
                                                    &liver.income) != EOF) {
        ul_insert_value(list, liver, 0);
    }
    
    fclose(file);
    return create_success_response(NULL);
}

RESPONSES write_to_file(const char* filename, p_unidirectional_list list)
{
    FILE* file = fopen(filename, "w");
    if (!file)
        return create_error_response(FILE_WRITE_ERROR, "File write error");
    
    p_unidirectional_list_item item = list->first;
    while (item)
    {
        fprintf(file, "%s %s %s %d %d %d %c %lf\n", 
                                                    item->data.surname, 
                                                    item->data.name, 
                                                    item->data.patronymic, 
                                                    item->data.day, 
                                                    item->data.month,
                                                    item->data.year,
                                                    item->data.gender,
                                                    item->data.income);
        item = item->next;
    }

    fclose(file);
    return create_success_response(NULL);
}

RESPONSES add_liver(p_unidirectional_list list, LIVER liver)
{
    size_t position = 0;
    p_unidirectional_list_item item = list->first;

    while (item && (item->data.year < liver.year || 
                    (item->data.year == liver.year && item->data.month < liver.month) || 
                    (item->data.year == liver.year && item->data.month == liver.month && item->data.day < liver.day)))
    {
        position++;
        item = item->next;
    }
    
    int status = ul_insert_value(list, liver, position);
    if (status != 0)
        return create_error_response(INVALID_INPUT, "Error with ul_insert_value");\

    return create_success_response(NULL);
}

int find_liver(p_unidirectional_list list, const char *surname, const char *name, const char *patronymic, Liver *result)
{
    p_unidirectional_list_item item = list->first;

    while (item) {
        if (strcmp(item->data.surname, surname) == 0 &&
            strcmp(item->data.name, name) == 0 &&
            strcmp(item->data.patronymic, patronymic) == 0) {
            
            *result = item->data;
            
            return 0;
        }

        item = item->next;
    }

    return 1;
}

