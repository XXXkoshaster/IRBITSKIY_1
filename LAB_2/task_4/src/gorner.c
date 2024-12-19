#include "../include/functions_2_4.h"

enum ERRORS method_gorner(double x, int degree, ...)
{
    if (degree <= 0) {
        printf("Degree is less than 0\n");
        return INVALID_INPUT;
    }

    va_list coefficients;
    va_start(coefficients, degree);

    double result = 0.0;

    for (int i = 0; i < degree; i++) {
        double coefficient = va_arg(coefficients, double);

        result = result * x + coefficient;

        if (isinf(result) || isnan(result)) {
            printf("Overflow\n");
            va_end(coefficients);
            return MY_OVERFLOW;
        }
    }

    printf("Result: %lf\n", result);
 
    va_end(coefficients);
    return DONE;
}