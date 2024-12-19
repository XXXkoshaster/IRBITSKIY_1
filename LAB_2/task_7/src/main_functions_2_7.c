#include "../include/functions_2_7.h"

enum ERRORS dichotomy_method(double min, double max, double eps, double (*function)(double), double* result)
{
    if (min > max)
        return INVALID_INPUT;

    if (eps <= 0)
        return INVALID_INPUT;

    if (function(min) * function(max) >= 0.) {
        printf("ERROR: For min = %lf and max = %lf, the function does not change sign, so the Dichotomy method can't calculate the root\n", min, max);
        return INVALID_INPUT;
    }

    double mid;

    while (fabs(max - min) > eps) {
        mid = (max + min) / 2;

        if (fabs(function(mid)) < eps) {
            *result = mid;
            return DONE;
        }

        if (function(min) * function(mid) < 0.) {
            max = mid;
        } else {
            min = mid;
        }
    }

    *result = mid;

    return DONE;
}