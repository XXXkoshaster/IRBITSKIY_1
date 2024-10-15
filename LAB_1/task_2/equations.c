#include "functions_2.h"

double eqt_exp(double epsilon)
{
    double fx, dfx;
    double inital_guess = 2.0;
    double x = inital_guess;

    do {
        fx = log(x) - 1.0;
        dfx = 1 / x;

        x = x - fx / dfx;
    } while(fabs(fx) > epsilon);
    
    return x;
}

double eqt_pi(double epsilon)
{
    double fx, dfx;
    double inital_guess = 2.0;
    double x = inital_guess;

    do {
        fx = cos(x) + 1.0;
        dfx = -sin(x);

        x = x - fx / dfx;
    } while(fabs(fx) > epsilon);
    
    return x;
}

double eqt_ln(double epsilon)
{
    double fx, dfx;
    double inital_guess = 2.0;
    double x = inital_guess;

    do {
        fx = exp(x) - 2.0;
        dfx = exp(x);

        x = x - fx / dfx;
    } while(fabs(fx) > epsilon);
    
    return x;
}

double eqt_sqrt(double epsilon)
{
    double fx, dfx;
    double inital_guess = 2.0;
    double x = inital_guess;

    do {
        fx = pow(x, 2.0) - 2.0;
        dfx = 2 * x;

        x = x - fx / dfx;
    } while(fabs(fx) > epsilon);
    
    return x;
}

double equation_y(double epsilon)
{
    int p = 2;
    double current = log(2) * 0.5;
    double previous = 0;
    double product = 0.5;
    do
    {
        previous = current;
        do {
            p++;
        } while (is_prime(p));
        product *= (p - 1.0)/p;
        current = log(p) * product;
    } while (fabs(previous - current) >= epsilon);
    return (-log(current));
}

double sum(int n)
{
    double sum = 1;
    for (int i = 2; i <= n; i++)
    {
        sum += 1.0/i;
    }

    return sum;

}

int is_prime (int number)
{
    if(number < 0) number *= -1;

    if (number == 0 || number == 1 || number == 2)
        return 0;

    if(number % 2 == 0) return 1;

    for (int i = 3; i <= floor(sqrt(number)); i+=2)
    {
        if (number % i == 0)
            return 1;
    }
    return 0;
}