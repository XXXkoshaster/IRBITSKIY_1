#include "functions_2.h"

enum errors geom_average(double *result, int count, ...)
{
    if (count < 1)
        return INVALID_INPUT;

    if (result == NULL)
        return NULL_PTR;

    *result = 1.0;

    va_list args;
    va_start(args, count);
    
    double number;

    for (int i = 0; i < count; i++)
    {   
        number = va_arg(args, double);
        
        if (isnan(number) || isinf(number))
        {
            va_end(args);
            return INVALID_INPUT;
        }

        if (check_overflow(&number)) {
            va_end(args);
            return MY_OVERFLOW;
        }

        *result *= number;
    }

    *result = pow(*result, 1.0 / count);

    va_end(args);
    return DONE;
}

int check_overflow(double* number)
{
    if(isnan(*number) || isinf(*number))
        return 1;

    return 0;
}

enum errors my_fast_pow(double* result, double base, int power)
{
    if (power == 0)
    {
        *result = 1;
        return DONE;
    }

    if (power == 1)
    {
        *result = base;
        return DONE;
    }

    if (power < 0)
    {
        base = 1 / base;
        power = -power;
    }

    if (power % 2 == 0) 
    {
        double tmp;
        
        my_fast_pow(&tmp, base, power / 2);

        if (check_overflow(&tmp))
            return MY_OVERFLOW;

        *result = tmp * tmp;
    } else {
        double tmp;

        my_fast_pow(&tmp, base, power - 1);

        if (check_overflow(&tmp))
            return MY_OVERFLOW;
        
        *result = base * tmp;
    }
    
    return DONE;
}