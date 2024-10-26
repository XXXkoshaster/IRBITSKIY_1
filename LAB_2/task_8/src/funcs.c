#include "../include/task_2_8.h"

enum ERRORS sum_in_base(char** result, const char* num_1, const char* num_2, int base)
{
    int length_1 = strlen(num_1);
    int length_2 = strlen(num_2);

    int max_length = length_1 > length_2 ? length_1 : length_2;

    *result = (char*)malloc(max_length + 2);
    if (*result == NULL) {
        return INVALID_MEMORY;
    }

    (*result)[max_length + 1] = '\0';

    int reminder = 0;
    int i = length_1 - 1;
    int j = length_2 - 1;
    int k = max_length; 

    while(k >= 0) {
        int sum = reminder; 

        if (i >= 0) {
            int r_part_1 = 0;
            enum ERRORS status = char_to_int(&r_part_1, num_1[i--], base);

            if (status != DONE) {
                free(*result); 
                return status;
            }

            sum += r_part_1;
        }

        if (j >= 0) {
            int r_part_2 = 0;
            enum ERRORS status = char_to_int(&r_part_2, num_2[j--], base);

            if (status != DONE) {
                free(*result); 
                return status;
            }
            
            sum += r_part_2;
        }

        (*result)[k--] = int_to_char(sum % base);
        reminder = sum / base;
    }

    if(reminder > 0) {
        (*result)[0] = int_to_char(reminder);
        return DONE;
    }

    if ((*result)[0] == '0') {
        char *new_result = strdup(*result + 1);
        free(*result); 
        *result = new_result;
        return DONE;
    }

    return DONE;    
}

enum ERRORS getting_sums(int base, int count_nums, ...)
{
    if (base < 2 || base > 36) {
        printf("Invalid base\n");
        return INVALID_INPUT;
    }

    if (count_nums <= 0) {
        printf("Invalid count of numbers\n");
        return INVALID_INPUT;
    }

    va_list args;
    va_start(args, count_nums);

    char* result = strdup("0");

    for (int i = 0; i < count_nums; i++) {
        const char* num = va_arg(args, const char *);
        
        char* new_result = strdup(result);
        
        if (new_result == NULL) {
            free(result);
            va_end(args);
            return NULL_PTR;
        }

        enum ERRORS status = sum_in_base(&new_result, result, num, base);
        
        if (status != DONE) {
            free(result);
            free(new_result);
            va_end(args);
            return status;
        }

        free(result); 
        result = new_result;
    }

    va_end(args);

    char* start = result;

    while (*result == '0' && *(result + 1) != '\0')
        result++;

    if (start != result) {
        char* new_result = strdup(result);
        free(start); 
        result = new_result;
    }
    
    printf("Result: %s\n", result);

    free(result); 

    return DONE;
}