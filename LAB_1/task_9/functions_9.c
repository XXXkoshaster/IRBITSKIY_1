#include "functions_9.h"

void fillArray(long *array, long size, long min, long max)
{
    for (long i = 0; i < size; i++) {
        array[i] = rand() % (max - min + 1) + min;
    }
}

void first_task(char* a, char* b)
{
    long long_a = strtol(a, NULL, 10), long_b = strtol(b, NULL, 10);
    
    long size = long_b - long_a + 1;
    long array[size];

    fillArray(array, size, long_a, long_b);
    
    printf("Array before finding min and max:\n");
    printf_array(array, size);

    find_min_and_max(array, size);

    printf("Array after swapping min and max:\n");
    printf_array(array, size);


}

void swap(long*a , long*b)
{
    long tmp = *a;
    *a = *b;
    *b = tmp;
}

void find_min_and_max(long* array, long size)
{
    long min = array[0];
    long max = array[0];

    long min_indx = 0;
    long max_indx = 0;

    for (long i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
            min_indx = i;
        }

        if (array[i] > max) {
            max = array[i];
            max_indx = i;
        }
    } 
    printf("Min_ind: %ld, Max_ind %ld\n", min_indx, max_indx);
    printf("Min: %ld, Max: %ld\n", min, max);
    swap(&array[min_indx], &array[max_indx]);  
}

long get_random_number(long a, long b)
{
    srand(time(NULL));
    return rand() % (b - a + 1) + a;
}

long find_close_number(long* array, long size, long origin)
{
    long close_number = array[0];

    for (long i = 1; i < size; i++) {
        if (labs(array[i] - origin) < labs(close_number - origin))
            close_number = array[i];
    }

    return close_number;
}

void second_task()
{   
    long size_a= get_random_number(10, 1000), size_b = get_random_number(10, 1000);
    long* arr_a = (long*)malloc(size_a * sizeof(long));
    long* arr_b = (long*)malloc(size_b * sizeof(long));
    long* arr_c = (long*)malloc(size_a * sizeof(long));

    if (arr_a == NULL || arr_b == NULL || arr_c == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    fillArray(arr_a, size_a, -1000, 1000);
    fillArray(arr_b, size_b, -1000, 1000);

    for (long i = 0; i < size_a; i++) 
        arr_c[i] = find_close_number(arr_b, size_b, arr_a[i]);
    
    printf("Arrray A:\n");
    printf_array(arr_a, size_a);

    printf("Arrray B:\n");
    printf_array(arr_b, size_b);
    
    printf("Arrray C:\n");
    printf_array(arr_c, size_a);
    
    free(arr_a);
    free(arr_b);
    free(arr_c);
}

void printf_array(long* array, long size)
{
    for (long i = 0; i < size; i++) {
        printf("%ld ", array[i]);
    }

    printf("\n");
}