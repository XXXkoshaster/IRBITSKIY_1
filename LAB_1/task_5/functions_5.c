#include "functions_5.h"

double factorial(int n)
{
    double result = 1.0;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

void first_expression(double x, double epsilon)
{
    double res = 0.0;
    double term = 1.0;
    int n = 1;

    while(fabs(term) > epsilon)
    {
        res += term;
        term *= x / n;
        ++n;
    }

    printf("First expression: %lf\n", res); 
    return;
}

void second_expression(double x, double epsilon)
{
    double res = 0.0;
    double term = 1.0;
    int n = 0;

    while(fabs(term) > epsilon)
    {
        res += term;
        term *= -(x * x) / ((2 * n + 1) * (2 * n + 2)); //-0.41614....
        ++n;
    }

    printf("Second expression: %lf\n", res); 
    return;
}

void third_expression(double x, double epsilon)
{
    if (x >= 1.0 || x <= -1.0)
    {
        printf("Indefinite value for Third expression\n");
        return;
    }

    int n = 0;
    double res = 0.0;
    double term = 1.0;

    while(fabs(term) > epsilon)
    {
        res += term;
        n++;
        term *= (9.0 * n  * n  * x * x) / (9.0 * n * n - 9.0 * n + 2.0);
    }
    
    printf("Third expression: %lf\n", res);
    return;
}

void fourth_expression(double x, double epsilon)
{
    int n = 0;
    double res = 0.0;
    double term = -1.0 * x * x / 2.0;
    
    if (x >= 1.0 || x <= -1.0)
    {
        printf("Indefinite value for Forth expression\n");
        return;
    }

    while(fabs(term) > epsilon)
    {
        res += term;
        n++;
        term *= -((2 * n + 1) * x * x) / (2 * n + 2);;
    }
    
    printf("Forth expression: %lf\n", res);
    return;
}