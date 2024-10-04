#include "functions_5.h"

int main(int argc, char **argv) {
    double x = 1.0;
    char* epsilon = argv[1];
    double epsilon_double = atof(epsilon);

    printf("First expression: %f\n", first_expression(x, epsilon_double));
    printf("Second expression: %f\n", second_expression(x, epsilon_double));
    printf("Third expression: %f\n", third_expression(x, epsilon_double));
    printf("Fourth expression: %f\n", fourth_expression(x, epsilon_double));

    return 0;
}
