#include "../include/utils.h"

enum ERRORS char_to_int(int* value, char chr, int base)
{
    if(isdigit(chr))
        *value = chr - '0';
    else if(isalpha(chr))
        *value = toupper(chr) - 'A' + 10;
    else 
        return INVALID_INPUT;
    
    if (*value >= base)
        return INVALID_INPUT;

    return DONE;
}

char int_to_char(int num)
{
    if (num < 10)
        return num + '0';
    else
        return num - 10 + 'A';
}

void heandler_status(enum ERRORS status) 
{
    switch (status)
    {
    case DONE:
        printf("Successful completed\n");
        break;
    case INVALID_INPUT:
        printf("Invalid input\n");
        break;
    case WRONG_PARAMETERS:
        printf("Wrong parameters\n");
        break;
    case MY_OVERFLOW: 
        printf("My overflow\n");
        break;
    case NULL_PTR:
        printf("Null pointer\n");
        break;
    case INVALID_MEMORY:
        printf("Invalid memory\n");
        break;
    case FILE_NOT_FOUND:
        printf("File not found\n");
        break;

    default:
        printf("Unknown error\n");
        break;
    }
}