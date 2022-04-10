#ifndef himmelblau_h
#define himmelblau_h

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double valueonly(int dim, double *x);
double valueandderivatives(int dim, double *x, double* grad,
  double *hessian_vecshaped);

#endif
