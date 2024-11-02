#include "../include/utils.h"

RESPONSES decarator_fopen(const char* path, const char* mode, FILE** file)
{
    if (!path || !mode || !file)
        return create_error_response(INVALID_INPUT, "input or otput file is NULL");

    (*file) = fopen(path, mode);

    if (!(*file))
        return create_error_response(INVALID_INPUT, "Invalid path");

    return create_success_response(NULL);
}

RESPONSES files_name_equial(const char* a, const char* b)
{
    char absolute_path_a[PATH_MAX];
    char absolute_path_b[PATH_MAX];

    if (!a || !b)
        return create_error_response(INVALID_INPUT, "input or otput file is NULL");

    if (realpath(a, absolute_path_a) == NULL)
        return create_error_response(INVALID_INPUT, "Invalid input path");

    if (realpath(b, absolute_path_b) == NULL)
        return create_error_response(INVALID_INPUT, "Invalid output path");

    if (my_strcmp(absolute_path_a, absolute_path_b) == 0)
        return create_error_response(INVALID_INPUT, "Files  are the same");

    return create_success_response(NULL);
}

int my_strcmp(const char* a, const char* b)
{
    while(*a != '\0' && *b != '\0') {
        if (*a != *b)
            return *a - *b;
        a++;
        b++;
    }

    return *a - *b;
}

int my_strlen(const char* a)
{
    int len = 0;

    while(*a != '\0') {
        len++;
        a++;
    }

    return len;
}

char* my_strcpy(char* dest, const char* src)
{
    char* start = dest;

    while(*src) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
    
    return start;
}

char* my_strcat(char* dest, const char* src)
{
    char* start = dest;

    while(*dest)
        dest++;

    while(*src) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return start;
}
