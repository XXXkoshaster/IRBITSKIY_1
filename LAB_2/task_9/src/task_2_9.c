#include "../include/functions_2_9.h"

int main(int argc, char** argv)
{
    enum ERRORS status = check_finite_representation(25, 3, 0.04, 0.004, 0.37);
    
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

    return 0;
}