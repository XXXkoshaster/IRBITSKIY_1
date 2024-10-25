#include "../include/functions_2_4.h"

int char_to_int(char c) 
{
    if (isdigit(c))
        return c - '0';
    else if (isalpha(c))
        return tolower(c) - 'a' + 10;
    return -1; 
}

char* decimal_to_base(int decimal, int base)
{
    if (decimal == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result; 
    }

        char* result = (char*)malloc(33 * sizeof(char)); // Максимальная длина для 32-битного числа
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

int convert_to_decimal(char* str, int base) {
    int num = 0;
    while (*str) {
        int value;

        if (*str >= '0' && *str <= '9') {
            value = *str - '0';

        } else if (*str >= 'A' && *str <= 'Z') {
            value = *str - 'A' + 10;

        } else if (*str >= 'a' && *str <= 'z') {
            value = *str - 'a' + 10;

        } else {
            return -1;
        }

        if (value >= base) {
            return -1;
        }
        if (check_overflow(num, base)) {
            return -1;
        }
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

int check_overflow(double a, double b) {
    if (a > 0 && b > DBL_MAX / a) {
        return 1;
    }
    return 0;
}
