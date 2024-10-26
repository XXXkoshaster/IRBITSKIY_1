#include "../include/task_2_10.h"

// Функция для вычисления значения полинома в точке x
enum ERRORS coef_calculation(double x, double *coefs, int count, double *res)
{
    if (res == NULL)
        return INVALID_INPUT; // Проверка на NULL указатель

    *res = 0; // Инициализация результата нулем
    double power_x = 1.0; // Инициализация переменной для хранения степеней x

    // Цикл по всем коэффициентам полинома
    for (int i = 0; i < count; ++i)
    {
        *res += coefs[i] * power_x; // Добавление текущего члена полинома к результату
        power_x *= x; // Переход к следующей степени x
    }

    return DONE; // Возвращение статуса успешного выполнения
}

// Функция для вычисления коэффициентов производной полинома
enum ERRORS calc_differ(double *coefs, int count, int iter)
{
    // Цикл по всем коэффициентам до (count - iter - 1)
    for (int j = 0; j < count - iter - 1; j++)
        coefs[j] = (j + 1) * coefs[j + 1]; // Вычисление коэффициента производной

    return DONE; // Возвращение статуса успешного выполнения
}

// Функция для разложения полинома в ряд Тейлора
enum ERRORS decomposition_of_a_polynomial(int count, double eps, double x, double **result, ...)
{
    if (count == 0) {
        printf("Uncorrect count\n");
        return INVALID_INPUT; // Проверка на некорректное количество коэффициентов
    }

    if (eps <= 0) {
        printf("Uncorrect epsilon \n");
        return INVALID_INPUT; // Проверка на некорректное значение точности
    }

    // Выделение памяти для массива входных коэффициентов
    double *inp_coef = (double *)malloc(sizeof(double) * count);
    
    if (inp_coef == NULL)
        return INVALID_MEMORY; // Проверка на успешное выделение памяти
    
    // Выделение памяти для массива результата
    *result = (double *)malloc(sizeof(double) * count);
    
    if (*result == NULL) {
        free(inp_coef); // Освобождение памяти в случае ошибки
        return INVALID_MEMORY;
    }
    
    // Инициализация списка переменных аргументов
    va_list a;
    va_start(a, result);
    
    // Заполнение массива входных коэффициентов
    for (int i = 0; i < count; i++)
        inp_coef[i] = va_arg(a, double);

    va_end(a);

    // Цикл по всем коэффициентам для вычисления разложения
    for (int i = 0; i < count; i++) {
        (*result)[i] = 0.0; // Инициализация текущего коэффициента результата нулем
       
        double prev_coef = (*result)[i]; // Сохранение предыдущего коэффициента
       
        // Вычисление текущего коэффициента разложения
        coef_calculation(x, inp_coef, count - i, &((*result)[i]));

        (*result)[i] /= factorial(i); // Деление на факториал текущего индекса

        // Вычисление коэффициентов производной
        calc_differ(inp_coef, count, i);
    
        // Проверка на достижение заданной точности
        if (i > 0 && fabs((*result)[i] - prev_coef) < eps)
            break;
    }

    free(inp_coef); // Освобождение памяти для входных коэффициентов
    
    print_coefficients(*result, count); // Печать коэффициентов разложения

    return DONE; // Возвращение статуса успешного выполнения
}

// Функция для печати коэффициентов полинома
void print_coefficients(double *coefs, int count)
{
    printf("Coefs of polynom:\n");
    // Цикл по всем коэффициентам
    for (int i = 0; i < count; i++)
    {
        printf("g%d = %lf\n", i, coefs[i]); // Печать текущего коэффициента
    }
}