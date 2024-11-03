#ifndef __STRINGS_H__
#define __STRINGS_H__

#include <stdlib.h>

#include "responses.h"
#include "utils.h"

typedef struct {
    char* data;
    int length;
} STRING;

RESPONSES create_string(const char* data);
RESPONSES delete_string(STRING* string);
RESPONSES compare_string(const STRING* a, const STRING* b);
RESPONSES equals_string(const STRING* a, const STRING* b);
RESPONSES copy_string(STRING* dest, const STRING* src);
RESPONSES copy_string_to_new(const STRING* src);
RESPONSES concanate_string(STRING* dest, const STRING* src);

void handle_error(RESPONSES response);
STRING* create_string_decorator(const char* data);
void compare_string_decorator(STRING* str_1, STRING* str_2);
STRING* copy_string_to_new_decorator(STRING* src);
void concatenate_string_decorator(STRING* dest, STRING* src);
void copy_string_decorator(STRING* dest, STRING* src);
void equals_strings_decorator(STRING* str_1, STRING* str_2);

#endif