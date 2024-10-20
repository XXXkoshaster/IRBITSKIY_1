#include "../include/functions_2_3.h"

char* my_strstr(const char* src, const char* origin)
{
    char* src_ptr = NULL, * origin_ptr = NULL;

    if (src == NULL || origin == NULL)
        return NULL;

    while(*src  != '\0') {
        if(*src == *origin) {
            int trigger_out = 1;

            src_ptr = (char*)src;
            origin_ptr = (char*)origin;   

            while(*src && *origin) {
                /*
                printf("\t\tsrc: %c, origin: %c\n", *src, *origin);
                */
                trigger_out = trigger_out && (*src == *origin);
                src++;
                origin++;
            }

            if(trigger_out && *origin == '\0')
                return src_ptr;
            
            origin = origin_ptr;
            src = src_ptr;
        }
        src++;
    }
    return NULL;
}

int count_lines(FILE* file)
{
    if (file == NULL)
        return -1;

    int count = 0;
    char buffer[BUFFER_SIZE];

    while(fgets(buffer, BUFFER_SIZE, file))
        count++;

    rewind(file);
    return count;
}