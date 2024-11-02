#include "../include/utils.h"

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