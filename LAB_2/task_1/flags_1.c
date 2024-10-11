#include "flags_1.h"

void flag_l(char* str)
{
    printf("Length of string %s:\t%ld\n",str, length_string(str));
}

void flag_r(char* str)
{
    size_t len = length_string(str);
    char* revesed_str = (char*)malloc((len + 1) * sizeof(char));
    
    revesed_str[0] = '\0';

    revesed_string(str, revesed_str, len);
    printf("Reversed string:\t%s\n", revesed_str);

    free(revesed_str);
}

void flag_u(char* str)
{
    char* result = (char*)malloc((length_string(str) + 1)* sizeof(char));

    result[0] = '\0';

    u_string(str, result);
    printf("Uppercase every second character:\t%s\n", result);

    free(result);
}

void flag_n(char* str)
{   
    size_t length_str = length_string(str);
    char* result = (char*)malloc((length_string(str) + 1) * sizeof(char));
    result[0] = '\0';
    
    n_string(str, result, length_str);
    printf("New string:\t%s\n", result);

    free(result);
}


void flag_c(char** strings, int argc)
{       
    char* result = (char*)malloc(1 * sizeof(char));
    result[0] = '\0';  

    c_string(result, strings, argc);
    printf("Concatenated string:\t%s\n", result);
    
    free(result);
}

void execute_flag(char** argv, int argc)
{
        if (*(*(argv + 1)) == '-' || *(*(argv + 1)) == '/') {
        switch (*(*(argv + 1) + 1))
        {
        case 'l':
            flag_l(*(argv + 2));
            break;

        case 'r':
            flag_r(*(argv + 2));
            break;
        
        case 'u':
            flag_u(*(argv + 2));
            break;
        
        case 'n':
            flag_n(*(argv + 2));
            break;

        case 'c':
            flag_c(argv, argc);
            break;

        default:
            printf("Flag is not finded\n");
            break;
        }
    } else {
        printf("Use - or / to use flag\n");
    }
}