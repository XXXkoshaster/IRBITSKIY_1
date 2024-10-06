#include "functions_5.h"

double factorial(int n) 
{
    unsigned int long result = 1;

    for (int i = 2; i <= n; i++) {
        
        if ((result > ULLONG_MAX / i)) {
            printf("Factorial overflow.\n");
            return 0;
        }

        result *= i;    
    }
    
    return result;
}

unsigned long long double_factorial(int n) {
    unsigned long long result = 1;
    
    for (int i = n; i > 1; i -= 2) {
        result *= i;
    }

    return result;
}

double first_expression(double x, double epsilon)
{
    double sum = 0.0;
    double term = 0.0;
    int n = 0;

    do {
        term = powl(x, n) / factorial(n);
        sum += term;
        n++;
    } while (fabs(term) > epsilon);

    return sum;
}

double second_expression(double x, double epsilon)
{
    double sum = 0.0;
    double term = 0.0;
    int n = 0;

    do {
        term = (powl(-1, n) * powl(x, 2 * n)) / factorial(2 * n);
        sum += term;
        n++; 
    } while (fabs(term) > epsilon);

    return sum;
}

double third_expression(double x, double epsilon)
{
    int n = 0;
    double sum = 0.0;
    double term = 1.0;

    while(fabs(term) > epsilon)
    {
        sum += term;
        n++;
        term *= (9.0 * n * n * x * x) / (9.0 * n * n - 9.0 * n + 2.0);
    }
    
    return sum;
}

double fourth_expression(double x, double epsilon)
{
    int n = 0;
    double sum = 0.0;
    double term = -1.0 * x * x / 2.0;
    
    while(fabs(term) > epsilon)
    {
        sum += term;
        n++;
        term *= (-1.0 * x * x * (2.0 * n - 1)) / (2.0 * n);
    }

    return sum;
}
