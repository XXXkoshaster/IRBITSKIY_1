#include "../include/strings.h"

void handle_error(RESPONSES response) 
{
    if (response.status != DONE) 
        printf("Error: %s\n", response.message);
}

STRING* create_string_decorator(const char* data)
{
    RESPONSES response = create_string(data);
    if (response.status != DONE) {
        handle_error(response);
        return NULL;
    }
    
    return (STRING*)response.data;
}

void compare_string_decorator(STRING* str_1, STRING* str_2) 
{
    RESPONSES response = compare_string(str_1, str_2);
    
    if (response.status != DONE)
        handle_error(response);

    printf("compare_string: %d\n", (int)(intptr_t)response.data);
}

void equals_strings_decorator(STRING* str_1, STRING* str_2) {
    RESPONSES response = equals_string(str_1, str_2);
    
    if (response.status != DONE) 
        handle_error(response);

    printf("equals_string: %d\n", (int)(intptr_t)response.data);
}

STRING* copy_string_to_new_decorator(STRING* src) {
    RESPONSES response = copy_string_to_new(src);
    if (response.status != DONE) {
        handle_error(response);
        return NULL;
    }

    return (STRING*)response.data;
}

void concatenate_string_decorator(STRING* dest, STRING* src) {
    RESPONSES response = concanate_string(dest, src);
    
    if (response.status != DONE) 
        handle_error(response);
    
    printf("concanate_string: %s\n", dest->data);
}

void copy_string_decorator(STRING* dest, STRING* src) {
    RESPONSES response = copy_string(dest, src);
    
    if (response.status != DONE) 
        handle_error(response);
    
    printf("copy_string: %s\n", dest->data);
}

