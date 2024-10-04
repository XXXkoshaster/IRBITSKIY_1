//#include "functions_5.h"
#include <math.h>   
#include <stdio.h>  
#include <stdlib.h> 

double factorial(int n) 
{
    double result = 1.0;

    for (int i = 1; i <= n; i++) {
        result *= i;
        
        if (result == 0) {
            printf("Factorial overflow.\n");
            return 0;
        }
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
    double sum = 0.0;
    double term = 0.0;
    int n = 0;

    do {
        term = (powl(3, 3 * n) * powl(factorial(n), 3) * powl(x, 2 * n)) / (factorial(3 * n));
        sum += term;
        n++;
    } while (fabs(term) > epsilon);

    return sum;
}

double fourth_expression(double x, double epsilon)
{
    double sum = 0.0;
    double term = 0.0;
    int n = 1;
    int max_iterations = 100000; 

    do {
        unsigned long long numerator = double_factorial(2 * n - 1);
        unsigned long long denominator = double_factorial(2 * n);

        if (numerator == 0 || denominator == 0) {
            printf("Factorial limit\n");
            break;
        }

        term = powl(-1, n) * (double)numerator / denominator * powl(x, 2 * n);
        sum += term;
        n++;

        if (n > max_iterations) {
            printf("Maximum iterations\n");
            break;
        }

    } while (fabs(term) > epsilon);

    return sum;
}
