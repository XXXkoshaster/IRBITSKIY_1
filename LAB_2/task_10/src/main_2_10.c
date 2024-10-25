#include "../include/task_2_10.h"

int main()
{
    double *coefs; 
    enum ERRORS status = decomposition_of_a_polynomial(4, 0.01, 1, &coefs, 1.0, -3.0, 3.0, -1.0);

    heandler_status(status);

    return 0;
}