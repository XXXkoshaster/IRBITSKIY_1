#ifndef TASK_2_H_
#define TASK_2_H_

#include <math.h>   
#include <stdio.h>  
#include <float.h>
#include <stdlib.h> 

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

double eqt_exp(double epsilon);
double eqt_pi(double epsilon);
double eqt_ln(double epsilon);
double eqt_sqrt(double epsilon);

#endif