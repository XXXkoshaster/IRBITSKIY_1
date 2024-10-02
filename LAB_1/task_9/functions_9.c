#include "functions_9.h"

void fillArray(long *array, long size, long min, long max)
{
    srand(time(NULL));

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

void printf_array(long* array, long size)
{
    for (long i = 0; i < size; i++) {
        printf("%ld ", array[i]);
    }

    printf("\n");
}