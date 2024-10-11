#include "functions_6.h"

double expression_a(double x)
{
    if (fabs(x) < 1e-10)
        return 1.0;

    return log(1 + x) / x;
}

double expression_b(double x)
{
    return exp(-(x * x) / 2);
}

double expression_c(double x)
{
    if (x >= 1.0 - 1e-10)
        return 1.0;
    
    if (x <= 1e-10)
        return 0.0;

    return log(1 / (1 - x));
}

double expression_d(double x)
{
    return pow(x, x);
}

double trapezoidal_method(double (*f)(double), double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.0;
    
    sum += f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        sum += 2 * f(a + i * h);
    }

    return (h / 2) * sum;
}

double integral(double epsilon, double (*f)(double), double a, double b)
{
    int n = 1000;
    double previous_result = 0.0;
    int max_iterations = 1000000;
    double result = trapezoidal_method(f, a, b, n);

    while (fabs(result - previous_result) > epsilon)
    {
        previous_result = result;
        n *= 2;
        result = trapezoidal_method(f, a, b, n);
    }
    
    if (n >= max_iterations)
    {
        printf("Max count interatins\n");
    }
    return result;
}
