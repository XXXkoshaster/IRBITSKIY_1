#include "funcions_2.h"

int check_overflow(double* number)
{
    if(isnann(*number) || isinff(*number))
        return 1;

    return 0;
}