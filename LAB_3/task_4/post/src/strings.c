#include "../include/strings.h"

RESPONSES create_string(const char* data)
{
    if (data == NULL)
        return create_error_response(INVALID_INPUT, "data is NULL");

    STRING* string = (STRING*)malloc(sizeof(STRING));
    if (string == NULL)
        return create_error_response(INVALID_ALLOCATION_MEMORY, "Memory allocation failed");
    
    string->length = my_strlen(data);
    string->data = (char *)malloc((string->length + 1) * sizeof(char));

    if (string->data == NULL) {
        return create_error_response(INVALID_ALLOCATION_MEMORY, "Memory allocation failed");
    }

    for (int i = 0; i < string->length; i++)
        string->data[i] = data[i];

    string->data[string->length] = '\0';

    return create_success_response(string);
}

RESPONSES delete_string(STRING* str) 
{
    if (str == NULL || str->data == NULL)
        return create_error_response(INVALID_INPUT, "str or str->data is NULL");

    free(str->data);
    str->data = NULL;
    str->length = 0;

    return create_success_response(NULL);
}

RESPONSES compare_string(const STRING* str_1, const STRING* str_2)
{
    if (str_1 == NULL || str_2 == NULL || str_1->data == NULL || str_2->data == NULL)
        return create_error_response(INVALID_INPUT, "str_1 or str_2 is NULL");

    if (str_1->length != str_2->length)
        return create_success_response((void*)(intptr_t)(str_1->length - str_2->length));

    return create_success_response((void*)(intptr_t)(my_strcmp(str_1->data, str_2->data)));
}

RESPONSES equals_string(const STRING* str_1, const STRING* str_2)
{
    if (str_1 == NULL || str_2 == NULL || str_1->data == NULL || str_2->data == NULL)
        return create_error_response(INVALID_INPUT, "str_1 or str_2 is NULL");

    return create_success_response((void*)(intptr_t)(my_strcmp(str_1->data, str_2->data)));
}

RESPONSES copy_string(STRING* dest, const STRING* src)
{
    if (dest == NULL || src == NULL || src->data == NULL)
        return create_error_response(INVALID_INPUT, "dest or src is NULL");

    free(dest->data);

    dest->data = (char*)malloc((src->length + 1) * sizeof(char));

    if (dest->data == NULL)
        return create_error_response(INVALID_ALLOCATION_MEMORY, "invalid alacation of memory");

    dest->data = my_strcpy(dest->data, src->data);
    dest->length = src->length;

    return create_success_response(dest->data);
}

RESPONSES copy_string_to_new(const STRING* src)
{
    if(src == NULL || src->data == NULL)
        return create_error_response(INVALID_INPUT, "src is NULL");

    return create_string(src->data);
}

RESPONSES concanate_string(STRING* dest, const STRING* src)
{
    if (dest == NULL || src == NULL || dest->data == NULL || src->data == NULL)
        return create_error_response(INVALID_INPUT, "dest or src is NULL");

    dest->data = (char*)realloc(dest->data, (dest->length + src->length + 1) * sizeof(char));
    
    if (dest->data == NULL)
        return create_error_response(INVALID_ALLOCATION_MEMORY, "invalid alacation of memory");

    my_strcat(dest->data, src->data);
    dest->length += src->length;

    return create_success_response(dest->data);
}

