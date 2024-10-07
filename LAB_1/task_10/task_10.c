#include "functions_10.h"

int main(int argc, char** argv)
{   
    int base;
    if (get_base(&base) < 2)
        return 1;
    
    char max_number[65] = "";
    int max_value = 0;
    int max_abs_value = -1;
    char input[65];

    while((strcmp(input, "Stop"))) {
        printf("Enter number (or 'Stop' to end): ");
        scanf("%s", input);

        int value = string_to_int(input, base);
        if (value == -1) {
            printf("Invalid number for base %d\n", base);
            continue;
        }
        check_if_max(&value, &max_value, &max_abs_value, max_number, input);
    }
    
    printf("Max number: %s\n", max_number);
    print_answer(max_value);

    return 0;
}
