#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "flags_1.h"

void print_hex(char* hex_x, int length);
void print_table(int x);
void convert_to_hex(long x);

int main(int argc, char* argv[])
{
    execute_flag(argv[2], argv[1]);
    return 0;
}

void print_hex(char* hex_x, int length)
{
    for (int i = length - 1; i >= 0; i--){
        printf("%c ", hex_x[i]);
    }
    printf("\n");
}

void print_table(int x)
{
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= x; j++) {
            printf("%d ", (int)pow(i, j));
        }
        printf("\n");
    }
}

void convert_to_hex(long x)
{
    char hex_digits[] = "0123456789ABCDF";
    char hex[100];
    int index = 0;

    if (x == 0) {
        printf("0\n");
        return;
    }

    while (x > 0) {
        int remainder = x % 16;
        hex[index++] = hex_digits[remainder];
        x /= 16;
    }

    print_hex(hex, index);
}
