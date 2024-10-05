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