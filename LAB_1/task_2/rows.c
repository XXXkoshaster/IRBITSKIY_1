#include "functions_2.h"

double row_exp(double epsilon)
{
    double sum = 0.0;
    double term = 0.0;
    int n = 0;

    do {
        term = 1 / factorial(n);
        sum += term;
        n++;
    } while (fabs(term) > epsilon);

    return sum;
}

double row_pi(double epsilon)
{
    double sum = 0.0;
    double term = 0.0;
    int n = 1;

    do {
        term = pow(-1.0, (n - 1)) / factorial(2 * n - 1);
        sum += term;
        n++;
    } while (fabs(term) > epsilon);

    return (4 * sum);
}

double row_ln(double epsilon)
{
    double sum = 0.0;
    double term = 0.0;
    int n = 1;

    do {
        term = pow(-1.0, (n - 1)) / factorial(n);
        sum += term;
        n++;
    } while (fabs(term) > epsilon);

    return sum;
}

double row_sqrt(double epsilon)
{
    double mult = 1.0;
    double term = 1.0;
    int k = 2;

    do {
        term = pow(2, pow(2.0, -k));
        mult *= term;
        k++;
    }  while (fabs(term - 1.0) > epsilon);

    return mult;
}

double row_y(double epsilon)
{
    double sum = 0.0;
    double term = 0.0;
    int k = 2;

    do {
        term = (1 / pow(sqrt(k), 2.0)) - (1 / k);
        sum += term;
        k++;
    } while (fabs(term) > epsilon);

    double res = -pow(row_pi(epsilon), 2.0) / 6.0 + sum;

    return res;
}
