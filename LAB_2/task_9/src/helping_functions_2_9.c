#include "../include/functions_2_9.h"

int gcd(int a, int b)
{
    while(b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

   return a;
}