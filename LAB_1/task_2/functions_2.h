#ifndef TASK_2_H_
#define TASK_2_H_

#include <math.h>   
#include <stdio.h>  
#include <float.h>
#include <stdlib.h> 

#define M_PI 3.14159265358979323846

double factorial(int n);

double row_exp(double epsilon);
double row_pi(double epsilon);
double row_ln(double epsilon);
double row_sqrt(double epsilon);
double row_y(double epsilon);

double lim_sqrt(double epsilon);
double lim_ln(double epsilon);
double lim_pi(double epsilon);
double lim_exp(double epsilon);
double limit_y(double epsilon);

double eqt_exp(double epsilon);
double eqt_pi(double epsilon);
double eqt_ln(double epsilon);
double eqt_sqrt(double epsilon);
double equation_y(double epsilon);
double sum(int n);
int is_prime (int number);

#endif