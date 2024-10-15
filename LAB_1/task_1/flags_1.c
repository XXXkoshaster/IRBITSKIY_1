#include "flags_1.h"

void flag_h(char* x)
{   
    is_multiple(x);
}

void flag_p(char* x)
{ 
    
    long long_x = strtol(x, NULL, 10);
    
    if (long_x == 1 || long_x == 0)
        printf("x is %ld\n", long_x);
    else if (is_prime(long_x))
        printf("x is prime\n");
    else
        printf("x is composite\n");
}

void flag_a(char* x)
{   
    if (*x == '-') {
        printf("Invalid x (x >= 0)\n");
        return;
    }

    printf("Sum is %d\n", sum(x));
}

void flag_f(char* x)
{   
    if (*x == '-') {
        printf("Invalid x (x >= 0)\n");
        return;
    }

    long long_x = strtol(x, NULL, 10);
    
    long result = factorial(long_x);
    if (result == -1) {
        printf("Memory overflow\n");
        return;
    } 
    
    printf("Result is %ld\n", result);
}

void flag_s(char *x)
{
    long long_x = strtol(x, NULL, 10);
    convert_to_hex(long_x);
}

void flag_e(char* x)
{
    if (*x == '-') {
        printf("Invalid x (x >= 0)\n");
        return;
    }
    
    long long_x = strtol(x, NULL, 10);
    if (long_x > 10) {
        printf("Inalid x (x <= 10)\n");
        return;
    }

    print_table(long_x);
}

void execute_flag(char* flag, char* x)
{
    if (*flag == '-' || *flag == '/') {
        switch (*(flag + 1))
        {
        case 'h':
            flag_h(x);
            break;

        case 'p':
            flag_p(x);
            break;
        
        case 'a':
            flag_a(x);
            break;
        
        case 'f':
            flag_f(x);
            break;

        case 's':
            flag_s(x);
            break;
               
        case 'e':
            flag_e(x);
            break;

        default:
            printf("Flag is not finded\n");
            break;
        }
    } else {
        printf("Use - or / to use flag\n");
    }
}