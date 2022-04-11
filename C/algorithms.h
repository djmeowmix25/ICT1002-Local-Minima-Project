#ifndef beale_h
#define beale_h

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void gradient_simple(double *x, double step, double *grad, int dim);
void gradient_momentum(double *x, double *m, double step, double *grad, double al, int dim);
void gradient_newton(double *x, double *grad, double *hessian_vecshaped, double epsilon, int dim);

#endif
