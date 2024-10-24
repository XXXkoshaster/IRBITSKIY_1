#include "../include/functions_2_7.h"

int main()
{
    double result;
    enum ERRORS status = dichotomy_method(-1, 2, 0.001, function, &result);
        
    switch (status)
    {
    case DONE:
        printf("Result is %f.\nSuccessful completed\n", result);
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

    return 0;
}