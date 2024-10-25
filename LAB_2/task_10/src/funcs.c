#include "../include/task_2_10.h"

// Функция вычисляет значение многочлена в точке x.
// Аргументы:
// - x: значение, в котором нужно вычислить многочлен.
// - coefs: массив коэффициентов многочлена.
// - count: количество коэффициентов.
// - res: указатель на переменную, в которую будет записан результат.
// Возвращает DONE при успешном выполнении или INVALID_INPUT, если res равен NULL.
enum ERRORS coef_calculation(double x, double *coefs, int count, double *res)
{
    if (res == NULL)
        return INVALID_INPUT;

    *res = 0;
    double power_x = 1.0;

    for (int i = 0; i < count; ++i)
    {
        *res += coefs[i] * power_x;
        power_x *= x;
    }

    return DONE;
}

// Функция вычисляет коэффициенты производной многочлена.
// Аргументы:
// - coefs: массив коэффициентов многочлена.
// - count: количество коэффициентов.
// - iter: текущая итерация дифференцирования.
// Возвращает DONE при успешном выполнении.
enum ERRORS calc_differ(double *coefs, int count, int iter)
{
    for (int j = 0; j < count - iter - 1; j++)
        coefs[j] = (j + 1) * coefs[j + 1];

    return DONE;
}

// Функция выполняет переразложение многочлена по степеням значения (x - a).
// Аргументы:
// - count: степень многочлена.
// - eps: точность вычислений.
// - x: значение, в котором нужно вычислить многочлен.
// - result: указатель на указатель, в который будет записан массив коэффициентов результирующего многочлена.
// - ...: переменное число аргументов, представляющих коэффициенты исходного многочлена.
// Возвращает DONE при успешном выполнении или соответствующую ошибку.
enum ERRORS decomposition_of_a_polynomial(int count, double eps, double x, double **result, ...)
{
    if (count == 0) {
        printf("Uncorrect count\n");
        return INVALID_INPUT;
    }

    if (eps <= 0) {
        printf("Uncorrect epsilon \n");
        return INVALID_INPUT;
    }

    double *inp_coef = (double *)malloc(sizeof(double) * count);
    
    if (inp_coef == NULL)
        return INVALID_MEMORY;
    
    *result = (double *)malloc(sizeof(double) * count);
    
    if (*result == NULL) {
        free(inp_coef);
        return INVALID_MEMORY;
    }
    
    va_list a;
    va_start(a, result);
    
    for (int i = 0; i < count; i++)
        inp_coef[i] = va_arg(a, double);

    va_end(a);

    for (int i = 0; i < count; i++) {
        (*result)[i] = 0.0;
       
        double prev_coef = (*result)[i];
       
        coef_calculation(x, inp_coef, count - i, &((*result)[i]));

        (*result)[i] /= factorial(i);

        calc_differ(inp_coef, count, i);
    
        if (i > 0 && fabs((*result)[i] - prev_coef) < eps)
            break;
    }

    free(inp_coef);
    
    print_coefficients(*result, count);

    return DONE;
}

void print_coefficients(double *coefs, int count)
{
    printf("Coefs of polynom:\n");
    for (int i = 0; i < count; i++)
    {
        printf("g%d = %lf\n", i, coefs[i]);
    }
}