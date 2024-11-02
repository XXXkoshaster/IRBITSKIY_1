#include "../include/core.h"

RESPONSES convert_decemial_to_2_pow_r(char* result, int number, int r, int* count)
{
    if (r < 1 || r > 5)
        return create_error_response(INVALID_INPUT, "Invalid r value (r < 1 or r > 5)\n");

    int mask, reminder;
    char symbols[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
    int flag_is_neg = 0;

    if (number < 0) {
        number = negative(number);
        flag_is_neg = 1;
    }

    while (number > 0) {
        mask = sub(1 << r, 1);
        
        reminder = number & mask;

        number = number >> r;
        result[*count] = symbols[reminder];
        *count = sum(*count, 1);
    }

    if (flag_is_neg) {
        result[*count] = '-';
        *count = sum(*count, 1);
    }

    return create_success_response(result);
}

void print_result(char* res, int count)
{   
    printf("Result: ");

    for (int i = sub(count, 1); i >= 0; i = sub(i, 1))
        printf("%c", res[i]);
        
    printf("\n");
}