#include "functions_2.h"

double factorial(int n) 
{
    double result = 1.0;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    
    return result;
}

double lim_exp(double epsilon)
{
    int n = 1;
    double prev;
    double term = pow(1.0 + (1.0 / n), n);

    do {
        n++;
        prev = term;
        term = pow(1.0 + (1.0 / n), n);
    } while (fabs(term - prev) > epsilon);

    return term;
}

double lim_pi(double epsilon)
{
    int n = 2;
    double current = 4.0, previous = 0;
    do
    {
        previous = current;
        current *= (4.0 * n * ( n - 1.0)) / pow(2.0 * n - 1.0, 2);
        n++;
    } while (fabs(previous - current) >= epsilon);
    return current;
}

double lim_ln(double epsilon)
{
    int n = 1;
    double prev;
    double term = n * (pow(2.0, 1.0 / n) - 1.0);

    do {
        n++;
        prev = term;
        term = n * (pow(2.0, 1.0 / n) - 1.0);
    } while (fabs(term - prev) > epsilon);

    return term;
}

double lim_sqrt(double epsilon)
{
    double x0 = 0.5;
    double xn = x0;
    double xn_next;
    int iteration = 0;
    int max_iterations = 1000;

    do {
        if (iteration > max_iterations) {
            break;
        }

        xn_next = xn - (xn * xn) / 2.0 + 1.0;
        xn = xn_next;

        iteration++;
    } while (fabs(xn_next - xn) < epsilon);

    return xn_next;
}

double limit_y(double epsilon)
{
    double previous = 0;
    double current = 1;
    int n = 1;
    
    do
    {
        previous = current;
        n *= 2;
        current = sum(n) - log(n);
    } while (fabs(previous - current) >= epsilon);

    return current;
}