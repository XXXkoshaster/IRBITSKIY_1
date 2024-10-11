#include "functions_5.h"

#define INCORECT_USAGE 1
#define INCORECT_X 2

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: <eps> <x>\n");
        return INCORECT_USAGE;
    }
    
    char* epsilon = argv[1];
    char* x = argv[2];

    double epsilon_double = atof(epsilon);
    double x_double = atof(x);
    
    if (x_double >= 1.0 || x_double <= -1.0) {
        printf("-1 < x < 1\n");
        return INCORECT_X;
    }
    if (x_double != 0) {
        printf("First expression: %f\n", first_expression(x_double, epsilon_double));
        printf("Second expression: %f\n", second_expression(x_double, epsilon_double));
        printf("Third expression: %f\n", third_expression(x_double, epsilon_double));
    } else {
        printf("Indtfinit value for First, Second, Third expressions\n");
    }

    printf("Fourth expression: %f\n", fourth_expression(x_double, epsilon_double));

    return 0;
}
