#include "functions_6.h"

int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("Invalid count of arguments\n");
        return 1;
    }

    char* epsilon = argv[1];
    double epsilon_double = atof(epsilon);
    double a = 0.0, b = 1.0;

    if (epsilon_double <= 0) {
        printf("Invalid epsilon\n");
        return 1;
    }

    if (epsilon_double < 1e-15) {
        printf("Epsilon is too small\n");
        epsilon_double = 1e-15; 
    }

    printf("Expsession a: %lf\n", integral(epsilon_double, expression_a, a, b));
    printf("Expsession b: %lf\n", integral(epsilon_double, expression_b, a, b));
    printf("Expsession c: %lf\n", integral(epsilon_double, expression_c, a, b));
    printf("Expsession d: %lf\n", integral(epsilon_double, expression_d, a, b));

    return 0;
}