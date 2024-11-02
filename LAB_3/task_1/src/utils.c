#include "../include/utils.h"

int sum(int summand, int addend)
{
    unsigned int carry = 0;

    while (addend != 0) {
        carry = summand & addend;
        summand = summand ^ addend;
        addend = carry << 1;
    }

    return summand;
}

int negative(int number)
{
    return sum(~number, 1);
}

int sub(int minuend, int subtrahend)
{
    return sum(minuend, negative(subtrahend));
}