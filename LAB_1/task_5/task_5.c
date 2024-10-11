#include "functions_5.h"

int main(int argc, char **argv) {
    char* epsilon = argv[1];
    char* x = argv[2];

    double epsilon_double = atof(epsilon);
    double x_double = atof(x);
    
    if (x_double >= 1.0 || x_double <= -1.0) {
        printf("-1 < x < 1\n");
        return 1;
    }

    printf("First expression: %f\n", first_expression(x_double, epsilon_double));
    printf("Second expression: %f\n", second_expression(x_double, epsilon_double));
    printf("Third expression: %f\n", third_expression(x_double, epsilon_double));
    printf("Fourth expression: %f\n", fourth_expression(x_double, epsilon_double));

    return 0;
}
