#include "functions_10.h"

void print_answer(int answer)
{
    char result[65];
    int bases[] = {9, 18, 27, 36};
    for (int i = 0; i < 4; i++) {
        int_to_string(answer, bases[i], result);
        printf("Base %d: %s\n", bases[i], result);
    }
}

void check_if_max(int* value, int* max_value, int* max_abs_value, char* max_number, char* input)
{
    int abs_value = abs(*value);
    
    if (abs_value > *max_abs_value) {
        *max_abs_value = abs_value;
        *max_value = *value;
        strcpy(max_number, input);  
    }
}

int get_base(int* base)
{
    printf("Enter base from 2 to 36: ");
    scanf("%d", base);

    if (*base < 2 || *base > 36) {
        printf("Invalid base\n");
    }

    return *base;
}

int char_to_value(char c) 
{
    if (isdigit(c)) 
        return c - '0';

    if (isupper(c))
        return c - 'A' + 10;
    
    return -1;
}

int string_to_int(const char* str, int base)
{
    int value = 0;
    while (*str) {
        int digit = char_to_value(*str++);
        
        if (digit < 0 || digit >= base) 
            return -1;
        
        value = value * base + digit;
    }

    return value;
}

void int_to_string(int value, int base, char* result)
{
    char buffer[65];
    int length = 0;
    
    int is_neg = value < 0;
    if (is_neg)
        value = -value;

    do {
        int digit = value % base;
        buffer[length++] = (digit < 10) ? '0' + digit : 'A' + digit - 10;
        value /= base;
    } while (value > 0);

    if (is_neg)
        buffer[length++] = '-';
        
    buffer[length] = '\0';

    for (int i = 0; i < length; i++) {
        result[i] = buffer[length - i - 1];
    }

    result[length] = '\0';
}