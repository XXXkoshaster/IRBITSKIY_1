#include "functions_5.h"

double first_expression(double x, double epsilon)
{
    double res = 0.0;
    double term = 1.0;
    int n = 1;

    while(fabs(term) > epsilon)
    {
        res += term;
        n++;
        term *= x / (x + 1);
    }

    return res;
}

double second_expression(double x, double epsilon)
{
    double res = 0.0;
    double term = 1.0;
    int n = 1;

    while(fabs(term) > epsilon)
    {
        res += term;
        n++;
        term *= (-1.0 * x * x) / (2.0 * n + 2.0);
    }
    return res;
}

double third_expression(double x, double epsilon)
{
    int n = 1;
    double res = 0.0;
    double term = 1.0;

    while(fabs(term) > epsilon)
    {
        res += term;
        n++;
        term *= (9.0 * (n + 1.0) * (n + 1.0) * x * x) / ((3.0 * n + 1) * (3.0 * n + 2));
    }
    
    return res;
}

double fourth_expression(double x, double epsilon)
{
    int n = 2;
    double res = 0.0;
    double term = -1.0 * x * x / 2.0;
    
    while(fabs(term) > epsilon)
    {
        res += term;
        n++;
        term *= (-1.0 * x * x * (2.0 * n + 1)) / (2.0 * (n + 1));
    }

    return res;
}
