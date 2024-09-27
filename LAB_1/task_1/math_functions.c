#include "math_functions.h"

long factorial(long x)
{
    if (x <= 1) {
        return 1; 
    } else {
        return x * factorial(x - 1);
    }
}


int sum(char* x)
{
    long long_x = strtol(x, NULL, 10);
    int sum = 0;    
    
    for (int i = 1; i <= long_x; i++) {
        sum += i;
    }
    
    return sum;
}

int is_prime(int x)
{
    for (int i = 2; i < x; i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int is_multiple(char* x) 
{
    int f = 0; 
    
    if (*x != '0')
        for (int i = 1; i <= 100; i++) {
            if (i % strtol(x, NULL, 10) == 0) {
                f = 1;
                printf("%d ", i);
            }
        }

    if (f == 0) 
        printf("No numbers with this x\n");
}