#include "../include/strings.h"

#define SUCCESS 0
#define INVALID_USAGE 1
#define INVALID_FLAG 2

void handle_error(RESPONSES response);
STRING* create_string_decorator(const char* data);
void compare_string_decorator(STRING* str_1, STRING* str_2);
STRING* copy_string_to_new_decorator(STRING* src);
void concatenate_string_decorator(STRING* dest, STRING* src);
void copy_string_decorator(STRING* dest, STRING* src);
void equals_strings_decorator(STRING* str_1, STRING* str_2);

int main()
{       
    STRING* str_1 = create_string_decorator("Hello");
    if (str_1 == NULL)
        return INVALID_USAGE;
    
    STRING* str_2 = create_string_decorator("Zell");
    if (str_2 == NULL) {
        delete_string(str_1);
        return INVALID_USAGE;
    }

    printf("str_1: %s\n", str_1->data);
    printf("str_2: %s\n", str_2->data);

    compare_string_decorator(str_1, str_2);
    equals_strings_decorator(str_1, str_2);

    STRING* str_3 = copy_string_to_new_decorator(str_1);
    if (str_3 == NULL) {
        delete_string(str_1);
        delete_string(str_2);
        return INVALID_USAGE;
    }
    printf("str_3: %s\n", str_3->data);

    concatenate_string_decorator(str_1, str_2);
    copy_string_decorator(str_1, str_2);

    delete_string(str_1);
    delete_string(str_2);
    delete_string(str_3);

    return SUCCESS;
}

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

