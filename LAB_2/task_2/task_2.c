#include "functions_2.h"

int main(int argc, char** argv)
{
    double result_average;
    enum errors error_status = geom_average(&result_average, 3, 2.0, 4.0, 8.0);

    if (error_status == DONE)
        printf("Geometric average: %lf\n", result_average);
    else
        printf("Error: %d\n", error_status);

    double result_pow;

    error_status = fast_pow(&result_pow, 4, 6);

    if (error_status == DONE)
        printf("Fast power: %lf\n", result_pow);
    else
        printf("Error: %d\n", error_status);

    return 0;
}