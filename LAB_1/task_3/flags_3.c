#include "functions_3.h"

void flag_q(char* a, char* b, char* c, char* eps)
{
    double arr[PERMUTATIONS_COUNT][3];
    double epsilon = atof(eps);
    double roots[2];
    int ans; 

    permutations(a, b, c, arr);
    
    for (int i = 0; i < PERMUTATIONS_COUNT; i++){
        ans = solve_quadratic(arr[i][0], arr[i][1], arr[i][2], epsilon, roots);
        
        printf("%f %f %f\n", arr[i][0], arr[i][1], arr[i][2]);
        
        switch (ans)
        {
        case 2:
            printf("Roots: %f %f\n", roots[0], roots[1]);
            break;
        
        case 1:
            printf("Root is %f\n", *roots);
            break;
        
        case 0:
            printf("Roots are not real numbers.\n");
            break;
        
        default:
            break;
        }
    }
}

void flag_m(char* a, char* b)
{
    long x = strtol(a, NULL, 10);
    long y = strtol(b, NULL, 10);

    if (is_multiple(x, y)) { 
        printf("%s is multiple to %s", a, b);
    } else {
        printf("%s is not multiple to %s", a, b);
    }
}

void flag_t(char* eps, char* a, char* b, char* c)
{   
    double x = atof(a);
    double y = atof(b);
    double z = atof(c);
    double epsilon = atof(eps);
    
    printf("epsilon: %s, a: %s, b: %s, c: %s\n", eps, a, b, c);

    if (is_triangle(x, y, z, epsilon)) {
        printf("Triangle is right\n");
    } else {
        printf("Triangle is not right\n");
    }
}

void execute_flag(char** argv)
{
    char *flag = argv[1];
    if (*flag == '-' || *flag == '/') {
    
        switch (*(flag + 1))
        {
        case 'q':
            flag_q(argv[2], argv[3], argv[4], argv[5]);
            break;

        case 'm':
            flag_m(argv[2], argv[3]);
            break;
        
        case 't':
            flag_t(argv[2], argv[3], argv[4], argv[5]);
            break;

        default:
            printf("Flag is not finded\n");
            break;
        }
    } else {
        printf("Use - or / to use flag\n");
    }
}