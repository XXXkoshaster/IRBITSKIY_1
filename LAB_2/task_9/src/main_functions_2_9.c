#include "../include/functions_2_9.h"

enum ERRORS has_finite_representation(int* flag, int numerator, int denominator, int base)
{
    if (denominator == 0)
        return INVALID_INPUT;
    
    if (base == 0)
        return INVALID_INPUT;

    if (numerator == 0)
        return DONE;

    // Сокращение дроби
    int common_divisor = gcd(numerator, denominator);
    numerator /= common_divisor;
    denominator /= common_divisor; 

    // Проверяем делимость знаменателя на основание системы счисления
    while(denominator % base == 0)
        denominator /= base;

    // Проверяем делимость на простые множители основания
    for (int i = 2; i <= base; i++) {
        if (base % i == 0) {
            while (denominator % i == 0) {
                denominator /= i;
            }   
        }
    }

    if (denominator == 1) {
        *flag = 1;
        return DONE;
    }

    *flag = 0;
    return DONE;
}

enum ERRORS check_finite_representation(int base, int count_fractions, ...)
{
    va_list args;
    va_start(args, count_fractions);

    if (base < 2)
        return INVALID_INPUT;

    for (int i = 0; i < count_fractions; i++) {
        double fraction = va_arg(args, double);
        
        if (fraction <= 0 || fraction >= 1)
            return INVALID_INPUT;

        double numerator = fraction;
        double denominator = 1;

        while(numerator != floor(numerator)) {
            numerator *= 10;
            denominator *= 10;
        }

        int flag = 0;

        enum ERRORS status = has_finite_representation(&flag, (int)numerator, (int)denominator, base);

        if(status != DONE) {
            va_end(args);
            return status;
        }  

        if (flag == 1)
            printf("Fraction %f has finite representation in base %d\n", fraction, base);
        else
            printf("Fraction %f doesn't have infinite representation in base %d\n", fraction, base);
    }

    va_end(args);

    return DONE;
}