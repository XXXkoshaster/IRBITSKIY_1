#include "../include/utils.h"

double factorial(int n)
{
    double result = 1.0;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    
    return result;
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