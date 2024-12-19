#include "../include/functions_2_4.h"

enum ERRORS find_kaprekar_number(int base, size_t count_nums, ...)
{
    if (count_nums <= 0) {
        printf("Count of numbers less then 0\n");
        return INVALID_INPUT;
    }

    va_list nums;
    va_start(nums, count_nums);

    size_t count_founded = 0;

    for (size_t i = 0; i < count_nums; i++) {
        char* num_in_base = va_arg(nums, char*);
        long long decimal_num = convert_to_decimal(num_in_base, base);

        if (decimal_num < 0) {
            printf("Invalid number was given\n");
            return INVALID_INPUT;
        }

        unsigned long long square = decimal_num * decimal_num;
        if (check_overflow(square, base))
            return MY_OVERFLOW;

        if (is_kaprekar(decimal_num, square, base)) {
            printf("Number %s is Kaprekar\n", num_in_base);
            count_founded++;
        } else {
            printf("Number %s is not Kaprekar\n", num_in_base);
        }
    }

    if (count_founded == 0) {
        printf("No Kaprekar numbers were found\n");
        va_end(nums);
        return DONE;
    }

    va_end(nums);

    return DONE;
}

int is_kaprekar(long long num, unsigned long long square, long long base)
{
    if (num == 1) 
        return 1;

    char* square_str = decimal_to_base(square, base);

    int len = strlen(square_str);
    
    for (long long i = 1; i < len; i++) {
        char left_str[256], right_str[256];

        strncpy(left_str, square_str, i);
        left_str[i] = '\0';

        strcpy(right_str, square_str + i);

        long long left = convert_to_decimal(left_str, base);
        long long right = convert_to_decimal(right_str, base);

        if (right > 0 && left + right == num) {
            return 1;
        }
    }
    return 0;
}
