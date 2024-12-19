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


