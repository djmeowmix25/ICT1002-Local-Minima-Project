#ifndef beale_h
#define beale_h

void gradient_simple(double *x, double step, double *grad);
void gradient_momentum(double *x, double *m, double step, double *grad, double a);
void gradient_newton(double *x, double step, double *grad, double *hessian_vecshaped);

#endif
