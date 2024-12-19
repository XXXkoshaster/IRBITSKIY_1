#include "../include/task_2_10.h"

int main()
{
    double *coefs = NULL;
    int a = -2;
    unsigned int degree = 4; 
    enum ERRORS status = decomposition_of_a_polynomial(a, &coefs, degree, -3., -3., -3., -3., -3.);

    switch (status)
    {
    case DONE:
        printf("Successful completed\n");
        printf("Coefs of g(x-a):\n");

        for (unsigned int i = 0; i <= degree; i++)
            printf("g_%u = %lf\n", i, coefs[i]);

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