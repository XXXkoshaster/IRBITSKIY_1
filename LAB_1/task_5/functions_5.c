//#include "functions_5.h"
#include <math.h>   
#include <stdio.h>  
#include <stdlib.h> 

double factorial(int n) 
{
    double result = 1.0;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    
    return result;
}

double first_expression(double x, double epsilon)
{
    double sum = 1.0;
    double term = 1.0;
    int n = 1;

    while (fabs(term) > epsilon) {
        term = powl(x, n) / factorial(n);
        sum += term;
        n++;
    }

    return sum;
}

double second_expression(double x, double epsilon)
{
    double sum = 1.0;
    double term = 1.0;
    int n = 1;

    while (fabs(term) > epsilon) {
        term = (powl(-1, n) * powl(x, 2 * n)) / factorial(2 * n);
        sum += term;
        n++;
    }

    return sum;
}

double third_expression(double x, double epsilon)
{
    double sum = 1.0;
    double term = 1.0;
    int n = 1;

    while (fabs(term) > epsilon) {
        term = (powl(3, 3 * n) * powl(factorial(n), 3) * powl(x, 2 * n)) / (factorial(3 * n));
        sum += term;
        n++;
    }

    return sum;
}

double fourth_expression(double x, double epsilon)
{
    double sum = 1.0;
    double term = 1.0;
    int n = 1;

    while (fabs(term) > epsilon) {
        term = (powl(-1, n) * factorial(factorial(2 * n - 1)) * powl(x, 2 * n)) / factorial(factorial(2 * n));
        sum += term;
        n++;
    }

    return sum;
}


