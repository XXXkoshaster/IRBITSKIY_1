#include "../include/task_2_10.h"

double calculation_of_polynomial(double *coefs, double a, unsigned int max_degree)
{
    double multiplier = 1, result = 0;

    for (unsigned int i = 0; i <= max_degree; ++i)
    {
        result += multiplier * coefs[i];
        multiplier *= a;
    }
    return result;
}

// По Биному Ньютона:
// g0 = f(a)
// g1 = f`(a)
// g2 = f``(a)/2!
// ...
enum ERRORS decomposition_of_a_polynomial(double a, double **coefs, unsigned int degree, ...)
{
    if (degree < 0)
        return INVALID_INPUT;

    int multiply = 1;
    unsigned int cur_degree = 1;

    double *start_coefs = (double *)malloc((degree + 1) * sizeof(double));
    *coefs = NULL;
    
    if (!start_coefs)
        return INVALID_MEMORY;

    double *new_coefs = (double *)malloc((degree + 1) * sizeof(double));
    if (!new_coefs)
    {
        free(start_coefs);
        return INVALID_MEMORY;
    }

    va_list args;
    va_start(args, degree);

    for (unsigned int i = 0; i <= degree; ++i)
        start_coefs[i] = va_arg(args, double);

    va_end(args);

    cur_degree = degree;
    for (unsigned int i = 0; i <= degree; ++i)
    {
        new_coefs[i] = calculation_of_polynomial(start_coefs, a, cur_degree);
        if (i)
        {
            multiply *= i;
            new_coefs[i] /= (double)multiply;
        }

        cur_degree--;

        for (unsigned int j = 0; j <= cur_degree; ++j)
            start_coefs[j] = start_coefs[j + 1] * (j + 1);
    }

    free(start_coefs);

    *coefs = new_coefs;

    return DONE;
}