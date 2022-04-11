#ifndef beale2d_h
#define beale2d_h
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double valueonly(int dim, double *x);
double valueandderivatives(int dim, double *x, double* grad,
  double *hessian_vecshaped);

#endif
