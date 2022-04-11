#include "himmelblau.h"


double valueonly(int dim, double *x)
{
  if (dim !=2)
  {
    printf("dim is not 2, but %d\n",dim);
    exit(2);
  }

  double p1,p2;

  p1 = x[0] * x[0] + x[1] - 11;
  p2 = x[0] + x[1] * x[1] - 7;

  double ret = p1*p1 + p2*p2;

  return ret;
}

double valueandderivatives(int dim, double *x , double* grad,
  double *hessian_vecshaped)
{
  if (dim !=2)
  {
    printf("dim is not 2, but %d\n",dim);
    exit(2);
  }

  if (grad == NULL)
  {
    printf("valueandderivatives_himmelblau: grad == NULL\n");
    exit(10);
  }
  if (hessian_vecshaped == NULL)
  {
    printf("valueandderivatives_himmelblau: hessian_vecshaped == NULL\n");
    exit(11);
  }

  double ret  = valueonly(dim, x);

  double p1,p2;

  // gradient
  p1 =  x[0] * x[0] + x[1] - 11;
  p2 =  x[0] + x[1] * x[1] - 7;

  grad[0] = 2 * p1 * 2 * x[0] + 2 * p2;
  grad[1] = 2 * p1 + 2 * p2 * 2 * x[1];

  // hessian
  hessian_vecshaped[0+2*0] = (4 * x[0] * 2 * x[0]) + (2 * p1 * 2) + 2;
  hessian_vecshaped[1+2*1] = 2 + (2 * p2 * 2) + (4 * x[1] * 2 * x[1]);
  hessian_vecshaped[1+2*0] = (4 * x[0]) + (4 * x[1]);
  hessian_vecshaped[0+2*1] = hessian_vecshaped[1+2*0];

  return ret;
}
