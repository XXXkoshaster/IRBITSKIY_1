#ifndef __UTILS_H__
#define __UTILS_H__

#include <iostream>

class BitwiseUtils
{
protected:
    static int sum(int summand, int addend)
    {
        unsigned int carry = 0;

        while (addend != 0) {
            carry = summand & addend;
            summand = summand ^ addend;
            addend = carry << 1;
        }

        return summand;
    }

    static int negative(int number)
    {
        return sum(~number, 1);
    }

    static int sub(int minuend, int subtrahend)
    {
        return sum(minuend, negative(subtrahend));
    }

    static int multiply(int multiplicand, int multipler)
    {
        int result = 0;

        while (multipler > 0) {
            if (multipler & 1) 
                result = sum(result, multiplicand);
            
            multiplicand <<= 1;
            multipler >>= 1;
        }

        return result;
    }
};

#endif