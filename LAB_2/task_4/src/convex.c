#include "../include/functions_2_4.h"

enum ERRORS check_convex_polygon(int count_coordinates, ...)
{
    if (count_coordinates <= 0) {
        printf("Count of coordinates is less than 0\n");
        return INVALID_INPUT;
    }

    if (count_coordinates % 2 != 0) {
        printf("Count of coordinates is not even\n");
        return INVALID_INPUT;
    }

    if ((count_coordinates / 2) < 3.0) {
        printf("Count of coordinates is less than 3\n");
        return INVALID_INPUT;
    }

    VERTEX* array = (VERTEX*)malloc(count_coordinates * sizeof(VERTEX));

    if (array == NULL) {
        printf("Array is NULL\n");
        return NULL_PTR;
    }

    va_list coordinates;
    va_start(coordinates, count_coordinates);

    for (int i = 0; i < count_coordinates; i++) {
        array[i].x = va_arg(coordinates, double);
        array[i].y = va_arg(coordinates, double);
    }


    if (!is_convex_polygon(array, count_coordinates)) {
        printf("Polygon is not convex\n");
        va_end(coordinates);
        return DONE;
    }

    printf("Polygon is convex\n");
    va_end(coordinates);
    return DONE;
}

double cross_product(VERTEX a, VERTEX b, VERTEX c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
} 

int is_convex_polygon(VERTEX* vertexes, int count_coordinates)
{
    int sign = cross_product(vertexes[0], vertexes[1], vertexes[2]) > 0;

    for (int i = 1; i < count_coordinates; i++) {
        if ((cross_product(vertexes[i], vertexes[(i + 1) % count_coordinates], vertexes[(i + 2) % count_coordinates]) > 0) != sign) {
            return 0;
        }
    }

    return 1;
}


