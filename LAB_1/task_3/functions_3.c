#include "functions_3.h"

int solve_quadratic(double a, double b, double c, double epsilon, double* roots)
{
    double discriminant = pow(b, 2) - (4 * a * c);

    if (discriminant > epsilon) {
        roots[0] = (-b + sqrt(discriminant)) / (2 * a);
        roots[1] = (-b - sqrt(discriminant)) / (2 * a);
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
    double double_a = atof(a);
    double double_b = atof(b);
    double double_c = atof(c);

    const double nums[3] = {double_a, double_b, double_c};
    int ind = 0;
    double comb[3];

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

int is_multiple(int a, int b)
{
    if (a % b == 0) {
        return 1;
    } else {
        return 0;
    }
}

int is_triangle(double a, double b, double c, double eps)
{
    double a2 = pow(a, 2);
    double b2 = pow(b, 2);
    double c2 = pow(c, 2);
    
    if (abs(a2 + b2 - c2) <= eps || abs(a2 + c2 - b2) <= eps || abs(b2 + c2 - a2) <= eps) {
        return 1;
    } else {
        return 0;
    }
}