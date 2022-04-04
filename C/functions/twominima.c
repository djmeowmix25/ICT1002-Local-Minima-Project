double valueonly(int dim, double *x)
{
  if (dim !=2)
  {
    printf("dim is not 2, but %d\n",dim);
    exit(2);
  }

  double p1,p2;

  p1 = -0.3 * exp(-10 * pow((x[0] - 0.5), 2) - 10 * pow((x[1] - 0.5), 2));
  p2 = 0.7 * exp(-10 * pow(x[0], 2) - 10 * pow(x[1], 2);

  double ret = p1-p2;

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
    printf("valueandderivatives_twominima: grad == NULL\n");
    exit(10);
  }
  if (hessian_vecshaped == NULL)
  {
    printf("valueandderivatives_twominima: hessian_vecshaped == NULL\n");
    exit(11);
  }

  double ret  = valueonly(dim, x);

  double p1,p2;

  // gradient
  p1 =  exp(-10 * pow((x[0] - 0.5), 2) - 10 * pow((x[1] - 0.5), 2));
  p2 =  exp(-10 * pow(x[0], 2) - 10 * pow(x[1], 2));
  p3 = x[0] - 0.5;
  p4 = x[1] - 0.5;

  grad[0] = 20 * 0.3 * p1 * p3 + 20 * 0.7 * p2 * x[0]
  grad[1] = 20 * 0.3 * p1 * p4 + 20 * 0.7 * p2 * x[1]

  // hessian
  hessian_vecshaped[0+2*0] = -20 * 20 * 0.3 * p1 * pow(p3, 2) + 20 * 0.3 * p1 + - 20 * 20 * 0.7 * p2 * pow(x[0], 2) + 20 * 0.7 * p2;
  hessian_vecshaped[1+2*1] = -20 * 20 * 0.3 * p1 * pow(p4, 2) + 20 * 0.3 * p1 + - 20 * 20 * 0.7 * p2 * pow(x[1], 2) + 20 * 0.7 * p2;
  hessian_vecshaped[1+2*0] = -20 * 20 * 0.3 * p1 * p3 * p4 + - 20 * 20 * 0.7 * p2 * x[0] * x[1];
  hessian_vecshaped[0+2*1] = hessian_vecshaped[1+2*0];

  return ret;
}
