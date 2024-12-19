#include "../include/functions_2_4.h"

// Функция для вычисления скалярного произведения
double dot(const VERTEX* a, const VERTEX* b) {
    return a->x * b->x + a->y * b->y;
}

// Функция для проверки на выпуклость
int is_convex(const VERTEX* v, int n) {
    VERTEX prev = v[n - 1];
    VERTEX cur, dir, normal;
    double d, dp;
    int sign, s;
    sign = 0;

    for (int i = 0; i < n; i++) {
        cur = v[i];
        // Вычисляем вектор направления ребра
        dir.x = cur.x - prev.x;
        dir.y = cur.y - prev.y;

        // Вычисляем нормаль к ребру
        normal.x = dir.y;
        normal.y = -dir.x;

        // Уравнение прямой: (p, n) + d = 0
        d = -(dot(&normal, &cur));

        // Проверяем знак точек
        sign = 0;
        for (int j = 0; j < n; j++) {
            dp = d + dot(&normal, &v[j]);
            if (fabs(dp) < EPSILON) 
                continue; 
            
            s = dp > 0 ? 1 : -1; 
            
            if (sign == 0) 
                sign = s; 
            else if (sign != s) 
                return 0; // Найдено несовпадение знаков
        }
        prev = cur;
    }

    return 1;
}

enum ERRORS check_convex_polygon(int count_vertexes, ...)
{
    if (count_vertexes < 3)
        return INVALID_INPUT;

    va_list vertexes;
    va_start(vertexes, count_vertexes);
    
    VERTEX* polygon = (VERTEX *)malloc(count_vertexes * sizeof(VERTEX));
    if (!polygon) {
        va_end(vertexes);
        return INVALID_MEMORY;
    }

    for (int i = 0; i < count_vertexes; i++) {
        VERTEX vertex = va_arg(vertexes, VERTEX);
        polygon[i] = vertex;
    }

    if (!is_convex(polygon, count_vertexes)) {
        printf("Polyon is not convex\n");
        free(polygon);
        va_end(vertexes);
        return DONE;
    }

    printf("Polyon is convex\n");

    free(polygon);
    va_end(vertexes);

    return DONE;
}