#include "functions_3.h"

int solve_quadratic(double a, double b, double c, double epsilon, double* roots) {
    if (fabs(a) < epsilon) { 
        if (fabs(b) < epsilon) {
            return (fabs(c) < epsilon) ? -1 : 0;
        } else {
            roots[0] = -c / b;
            return 1;
        }
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > epsilon) {
        double sqrt_disc = sqrt(discriminant);
        roots[0] = (-b + sqrt_disc) / (2 * a);
        roots[1] = (-b - sqrt_disc) / (2 * a);
        return 2; 
    } else if (discriminant >= -epsilon) {
        roots[0] = -b / (2 * a);
        return 1; 
    } else {
        return 0; 
    }
}

void permutations(char* a, char* b, char* c, double arr[PERMUTATIONS_COUNT][3]) 
{    
    double nums[3] = {atof(a), atof(b), atof(c)};
    double comb[3];
    int ind = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue; 
            for (int k = 0; k < 3; k++) { 
                if (k == i || k == j) continue;
                comb[0] = nums[i];
                comb[1] = nums[j];
                comb[2] = nums[k];

                if (is_unique(arr, ind, comb)) { 
                    arr[ind][0] = nums[i];
                    arr[ind][1] = nums[j];
                    arr[ind][2] = nums[k];
                    ind ++;
                }
            }
        }
    }
}

int is_unique(double arr[PERMUTATIONS_COUNT][3], int ind, double comb[3]) {
    for (int i = 0; i < ind; i++) {
        if (arr[i][0] == comb[0] && arr[i][1] == comb[1] && arr[i][2] == comb[2]) return 0;
    }
    return 1;
}

int is_multiple(int a, int b) {
    return (a % b == 0);
}

int is_triangle(double a, double b, double c, double eps) {
    double a2 = a * a;
    double b2 = b * b;
    double c2 = c * c;

    return (fabs(a2 + b2 - c2) <= eps || fabs(a2 + c2 - b2) <= eps || fabs(b2 + c2 - a2) <= eps);
}