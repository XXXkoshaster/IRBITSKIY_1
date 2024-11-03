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
