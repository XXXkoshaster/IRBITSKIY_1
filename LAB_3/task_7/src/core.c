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
        ul_insert_value(list, &liver, 0);
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
    while (item) {
        LIVER *liver = (LIVER *)item->data;
        fprintf(file, "%s %s %s %d %d %d %c %lf\n", 
                                                    liver->surname, 
                                                    liver->name, 
                                                    liver->patronymic, 
                                                    liver->day, 
                                                    liver->month,
                                                    liver->year,
                                                    liver->gender,
                                                    liver->income);
        item = item->next;
    }

    fclose(file);
    return create_success_response(NULL);
}

RESPONSES find_liver(p_unidirectional_list list, const char *surname, const char *name, const char *patronymic, LIVER *result)
{
    if (!list || !surname || !name || !patronymic)
        return create_error_response(INVALID_INPUT, "Invalid input");

    p_unidirectional_list_item item = list->first;

    while (item) {
        LIVER *liver = (LIVER *)item->data;
        if (strcmp(liver->surname, surname) == 0 &&
            strcmp(liver->name, name) == 0 &&
            strcmp(liver->patronymic, patronymic) == 0) {
            
            *result = *liver;
            
            return create_success_response(NULL);
        }

        item = item->next;
    }

    return create_error_response(NOT_FOUND, "Liver not found");
}

RESPONSES add_liver(p_unidirectional_list list, LIVER liver, p_unidirectional_list mod_list)
{
    if (!list)
        return create_error_response(INVALID_INPUT, "Invalid input");

    size_t position = 0;
    p_unidirectional_list_item item = list->first;

    while (item) {
        LIVER *current_liver = (LIVER *)item->data;

        if (current_liver->year > liver.year ||
            (current_liver->year == liver.year && current_liver->month > liver.month) ||
            (current_liver->year == liver.year && current_liver->month == liver.month && current_liver->day > liver.day)) {
            break;
        }

        position++;
        item = item->next;
    }

    LIVER *new_liver = (LIVER *)malloc(sizeof(LIVER));
    if (!new_liver)
        return create_error_response(INVALID_ALLOCATION_MEMORY, "Memory allocation error");
    *new_liver = liver;

    int status = ul_insert_value(list, new_liver, position);
    if (status != 0) {
        free(new_liver);
        return create_error_response(INVALID_INPUT, "Error with ul_insert_value");
    }

    add_modification(0, position, liver, mod_list);

    return create_success_response(NULL);
}


RESPONSES update_liver(p_unidirectional_list list, const char *surname, const char *name, const char *patronymic, LIVER new_data, p_unidirectional_list mod_list)
{
    if (!list || !surname || !name || !patronymic || !list->first)
        return create_error_response(INVALID_INPUT, "Invalid input");

    p_unidirectional_list_item item = list->first;

    while (item) {
        LIVER *liver = (LIVER *)item->data;
        if (strcmp(liver->surname, surname) == 0 &&
            strcmp(liver->name, name) == 0 &&
            strcmp(liver->patronymic, patronymic) == 0) {
            
            add_modification(1, 0, *liver, mod_list);

            *liver = new_data;
            
            return create_success_response(NULL);
        }

        item = item->next;
    }

    return create_error_response(NOT_FOUND, "Liver not found");
}

RESPONSES delete_liver(p_unidirectional_list list, const char *surname, const char *name, const char *patronymic, p_unidirectional_list mod_list)
{
    if (!list || !surname || !name || !patronymic || !list->first)
        return create_error_response(INVALID_INPUT, "Invalid input");

    size_t position = 0;
    p_unidirectional_list_item item = list->first;

    while (item) {
        LIVER *liver = (LIVER *)item->data;
        if (strcmp(liver->surname, surname) == 0 &&
            strcmp(liver->name, name) == 0 &&
            strcmp(liver->patronymic, patronymic) == 0) {
            
            LIVER* removed;

            int status = ul_remove_value(list, position, removed);
            if (status != 0)
                return create_error_response(INVALID_INPUT, "Error with ul_remove_value");
            
            add_modification(2, position, *removed, mod_list);

            return create_success_response(removed);
        }

        position++;
        item = item->next;
    }

    return create_error_response(NOT_FOUND, "Liver not found");
}

RESPONSES add_modification(int type, size_t position, LIVER liver, p_unidirectional_list mod_list)
{
    P_MODIFICATION new_mod = (P_MODIFICATION)malloc(sizeof(MODIFICATION));
    if (!new_mod)
        return create_error_response(INVALID_ALLOCATION_MEMORY, "Memory allocation error");

    new_mod->type = type;
    new_mod->position = position;
    new_mod->liver = liver;

    int status = ul_insert_value(mod_list, new_mod, 0);
    
    if (status != 0) {
        free(new_mod);
        return create_error_response(INVALID_INPUT, "Error with ul_insert_value");
    }

    return create_success_response(NULL);
}

void undo_last_modification(p_unidirectional_list list, p_unidirectional_list mod_list, size_t n)
{
    for (size_t i = 0; i < n && mod_list->first; i++) {
        P_MODIFICATION mod = (P_MODIFICATION)mod_list->first->data;
        ul_remove_value(mod_list, 0, (void **)&mod);

        if (mod->type == 0) {
            LIVER* removed;
            ul_remove_value(list, mod->position, (void **)&removed);
            free(removed);
        } else if (mod->type == 1) {
            p_unidirectional_list_item item = list->first;

            for (size_t j = 0; j < mod->position; j++) 
                item = item->next;

            item->data = malloc(sizeof(LIVER));
            if (item->data)
                *(LIVER *)item->data = mod->liver;
        } else {
            LIVER* new_liver = (LIVER *)malloc(sizeof(LIVER));
            
            if (new_liver) {
                *new_liver = mod->liver;
                ul_insert_value(list, new_liver, mod->position);
            }
        }
    }
}