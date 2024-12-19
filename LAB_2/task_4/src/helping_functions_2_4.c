#include "../include/functions_2_4.h"

int char_to_int(char c) 
{
    if (isdigit(c))
        return c - '0';
    else if (isalpha(c))
        return toupper(c) - 'A' + 10;
    return -1; 
}

char* decimal_to_base(long long decimal, int base)
{
    static int ll_size = sizeof(long long) * 8;

    if (decimal == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result; 
    }

    char* result = (char*)malloc(ll_size * sizeof(char));
    int index = 0;
    int is_negative = 0;

    if (decimal < 0) {
        is_negative = 1;
        decimal = -decimal;
    }

    while (decimal > 0) {
        int remainder = decimal % base;
        if (remainder < 10) {
            result[index++] = '0' + remainder;
        } else {
            result[index++] = 'A' + (remainder - 10);
        }
        decimal /= base;
    }

    if (is_negative) {
        result[index++] = '-';
    }

    result[index] = '\0';

    // Обратный порядок символов
    for (int i = 0; i < index / 2; i++) {
        char temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }

    return result;
}

long long convert_to_decimal(char* str, int base) {
    long long num = 0;

    while (*str) {
        int value = char_to_int(*str);

        if (value == -1 || value >= base)
            return -1;
    
        if (check_overflow(num, base)) 
            return -1;
        
        num = num * base + value;
        str++;
    }

    return num;
}

void heandler_status(enum ERRORS status) 
{
    switch (status)
    {
    case DONE:
        printf("Successful completed\n");
        break;
    case INVALID_INPUT:
        printf("Invalid input\n");
        break;
    case WRONG_PARAMETERS:
        printf("Wrong parameters\n");
        break;
    case MY_OVERFLOW: 
        printf("My overflow\n");
        break;
    case NULL_PTR:
        printf("Null pointer\n");
        break;
    case INVALID_MEMORY:
        printf("Invalid memory\n");
        break;
    case FILE_NOT_FOUND:
        printf("File not found\n");
        break;

    default:
        printf("Unknown error\n");
        break;
    }
}

int check_overflow(long long num, int base) {
    if (num > (LLONG_MAX - base) / base) {
        return 1;
    }
    return 0;
}
