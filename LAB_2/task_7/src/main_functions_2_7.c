#include "../include/functions_2_7.h"

enum ERRORS dichotomy_method(double min, double max, double eps, double (*function)(double), double* result)
{
    if (min > max)
        return INVALID_INPUT;

    if (eps <= 0)
        return INVALID_INPUT;

    if (function(min) * function(max) > 0)
        return INVALID_INPUT;

    double mid;

    while (fabs(max - min) > eps) {
        mid = (max + min) / 2;

        if (function(mid) == 0) {
            *result = mid;
            return DONE;
        }

        if (function(min) * function(mid) < 0)
            max = mid;
        else
            min = mid;
    }

    *result = mid;

    return DONE;
}