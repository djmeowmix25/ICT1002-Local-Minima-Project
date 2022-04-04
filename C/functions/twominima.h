#ifndef twominima_h
#define twominima_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double valueonly(int dim, double *x);
double valueandderivatives(int dim, double *x, double* grad,
  double *hessian_vecshaped);

#endif
