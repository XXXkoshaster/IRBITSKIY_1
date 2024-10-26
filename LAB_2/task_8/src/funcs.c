#include "../include/task_2_8.h"

// Функция для суммирования двух чисел, представленных в виде строк в заданной системе счисления
enum ERRORS sum_in_base(char** result, const char* num_1, const char* num_2, int base)
{
    // Вычисление длины входных строк
    int length_1 = strlen(num_1);
    int length_2 = strlen(num_2);

    // Определение максимальной длины
    int max_length = length_1 > length_2 ? length_1 : length_2;

    // Выделение памяти для строки результата
    *result = (char*)malloc(max_length + 2);
    if (*result == NULL) {
        return INVALID_MEMORY;
    }

    // Инициализация строки результата
    (*result)[max_length + 1] = '\0';

    int reminder = 0; // Переменная для хранения переноса
    int i = length_1 - 1; // Индекс для первой строки
    int j = length_2 - 1; // Индекс для второй строки
    int k = max_length; // Индекс для строки результата

    // Итерация по цифрам строк справа налево
    while(k >= 0) {
        int sum = reminder; // Инициализация суммы переносом

        // Суммирование цифр первой строки
        if (i >= 0) {
            int r_part_1 = 0;
            enum ERRORS status = char_to_int(&r_part_1, num_1[i--], base);

            if (status != DONE) {
                free(*result); // Освобождение памяти в случае ошибки
                return status;
            }

            sum += r_part_1;
        }

        // Суммирование цифр второй строки
        if (j >= 0) {
            int r_part_2 = 0;
            enum ERRORS status = char_to_int(&r_part_2, num_2[j--], base);

            if (status != DONE) {
                free(*result); // Освобождение памяти в случае ошибки
                return status;
            }
            
            sum += r_part_2;
        }

        // Преобразование суммы в символ и сохранение в строке результата
        (*result)[k--] = int_to_char(sum % base);
        reminder = sum / base; // Обновление переноса
    }

    // Обработка оставшегося переноса
    if(reminder > 0) {
        (*result)[0] = int_to_char(reminder);
        return DONE;
    }

    // Удаление ведущих нулей из результата
    if ((*result)[0] == '0') {
        char *new_result = strdup(*result + 1);
        free(*result); // Освобождение старой строки результата
        *result = new_result;
        return DONE;
    }

    return DONE;    
}

// Функция для суммирования нескольких чисел, представленных в виде строк в заданной системе счисления
enum ERRORS getting_sums(int base, int count_nums, ...)
{
    // Проверка корректности системы счисления
    if (base < 2 || base > 36) {
        printf("Invalid base\n");
        return INVALID_INPUT;
    }

    // Проверка корректности количества чисел
    if (count_nums <= 0) {
        printf("Invalid count of numbers\n");
        return INVALID_INPUT;
    }

    va_list args;
    va_start(args, count_nums);

    char* result = strdup("0"); // Инициализация результата как "0"

    // Итерация по входным числам
    for (int i = 0; i < count_nums; i++) {
        const char* num = va_arg(args, const char *);
        
        char* new_result = strdup(result);
        
        if (new_result == NULL) {
            free(result);
            va_end(args);
            return NULL_PTR;
        }

        // Суммирование текущего числа с результатом
        enum ERRORS status = sum_in_base(&new_result, result, num, base);
        
        if (status != DONE) {
            free(result);
            free(new_result);
            va_end(args);
            return status;
        }

        free(result); // Освобождение старого результата
        result = new_result;
    }

    va_end(args);

    char* start = result;

    // Удаление ведущих нулей из результата
    while (*result == '0' && *(result + 1) != '\0')
        result++;

    if (start != result) {
        char* new_result = strdup(result);
        free(start); // Освобождение старого результата
        result = new_result;
    }
    
    printf("Result: %s\n", result);

    free(result); // Освобождение памяти результата
    
    return DONE;
}