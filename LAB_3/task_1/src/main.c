#include "../include/core.h"

int main()
{
    int count = 0;
    char result[33]; //динамика. выделеть память в функции 
    RESPONSES response = convert_decemial_to_2_pow_r(result, 145, 5, &count);

    if (response.status == DONE)
        print_result(response.data, count);
    else
        printf("Error with massege: %s", response.message);

    return 0;
}