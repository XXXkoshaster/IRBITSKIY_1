#include "math_functions.h"

long factorial(long x) {
    if (x < 0) 
        return -1;
   
    long result = 1; 
    for (long i = 2; i <= x; i++) {
        result *= i;
    }
    
    return result;
}


int sum(char* x)
{
    long long_x = strtol(x, NULL, 10);
    int sum = 0;    
    
    if (long_x < 1) 
        return 0;
    
    for (int i = 1; i <= long_x; i++) {
        sum += i;
    }
    
    return sum;
}

int is_prime(int x) 
{
    if (x < 2) 
        return 0;
    
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) 
            return 0;
    }
    
    return 1;
}

int is_multiple(char* x) 
{
    int f = 0; 
    int num = strtol(x, NULL, 10);
    
    if (num == 0)
        return -1;
        
    for (int i = 1; i <= 100; i++) {
        if (i % num == 0) {
            f = 1;
            printf("%d ", i);
        }
    }

    if (f == 0) 
        printf("No numbers with this x\n");

    return f;
}