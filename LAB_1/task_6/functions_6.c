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

double trapezoidal(double (*f)(double), double a, double b, int n)
{
    double result = 0.0;
    double delta_x = (b - a) / n;

    for (int i = 0; i < n; i++)
    {
        double first_value = f(a + i * delta_x);
        double second_value = f(a + (i + 1) * delta_x);
        result += (first_value + second_value) / 2.0 * delta_x;
    }

    return result;
}

double integral(double epsilon, double (*f)(double), double a, double b)
{
    int n = 1;
    double result = trapezoidal(f, a, b, n);
    double prev_result = result;

    do
    {
        n *= 2;
        prev_result = result;
        result = trapezoidal(f, a, b, n);
    } while (fabs(result - prev_result) > epsilon);

    return result;
}
