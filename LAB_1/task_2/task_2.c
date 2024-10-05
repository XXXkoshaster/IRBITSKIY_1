#include "functions_2.h"

int main(int argc, char **argv) {
    char* epsilon = argv[1];
    double epsilon_double = atof(epsilon);

    printf("exp with row: %f\n", row_exp(epsilon_double));
    printf("exp with lims: %f\n", lim_exp(epsilon_double));
    printf("exp with eqt: %f\n\n", eqt_exp(epsilon_double));

    printf("pi with row: %f\n", row_pi(epsilon_double));
    printf("pi with lims: %f\n", lim_pi(epsilon_double));
    printf("pi with eqt: %f\n\n", eqt_pi(epsilon_double));

    printf("ln2 with row: %f\n", row_ln(epsilon_double));
    printf("ln2 with lims: %f\n", lim_ln(epsilon_double));
    printf("ln2 with eqt: %f\n\n", eqt_ln(epsilon_double));

    printf("sqrt(2) with row: %f\n", row_sqrt(epsilon_double));
    printf("sqrt(2) with lims: %f\n", lim_sqrt(epsilon_double));
    printf("sqrt(2) with eqt: %f\n\n", eqt_sqrt(epsilon_double));

    printf("y with row: %f\n", row_y(epsilon_double));

    return 0;
}