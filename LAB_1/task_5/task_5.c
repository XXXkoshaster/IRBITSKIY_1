#include "functions_5.h"

int main() {
    double x = 1.0;
    double epsilon = 0.0001;

    printf("First expression: %f\n", first_expression(x, epsilon));
    printf("Second expression: %f\n", second_expression(x, epsilon));
    printf("Third expression: %f\n", third_expression(x, epsilon));
    printf("Fourth expression: %f\n", fourth_expression(x, epsilon));

    return 0;
}
