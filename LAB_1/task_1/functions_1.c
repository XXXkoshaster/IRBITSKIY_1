#include "functions_1.h"

long factorial(long x) {
    if (x < 0) 
        return -1;
   
    long result = 1; 
    for (long i = 2; i <= x; i++) {
        if (result > LONG_MAX / i) 
            return -1;
            
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

void print_hex(char* hex_x, int length)
{
    for (int i = length - 1; i >= 0; i--){
        printf("%c ", hex_x[i]);
    }
    printf("\n");
}

long long int_pow(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

void print_table(int x)
{
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= x; j++) {
            printf("%lld ", int_pow(i, j));
        }
        printf("\n");
    }
}

void convert_to_hex(long x)
{
    char hex_digits[] = "0123456789ABCDEF";
    char hex[100];
    int index = 0;

    if (x < 0) x = -x;

    if (x == 0) {
        printf("0\n");
        return;
    }

    while (x > 0) {
        int remainder = x % 16;
        hex[index++] = hex_digits[remainder];
        x /= 16;
    }
    
    print_hex(hex, index);
}