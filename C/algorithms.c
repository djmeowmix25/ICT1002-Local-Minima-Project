void gradient_simple(double *x, double step, double *grad){
    unsigned int size = sizeof(x) / sizeof(x[0])

    for(int i = 0; i < size; i++){
        x[i] = x[i] - step * (grad[i]);
    }
}

void gradient_momentum(double *x, double *m, double step, double *grad, double a){
    unsigned int size = sizeof(x) / sizeof(x[0])

    for(int i = 0; i < size; i++){
        m[i] = a * (m[i]) + step * (grad[i]);
        x[i] = x[i] - m[i];
    }
}

void gradient_newton(double *x, double step, double *grad, double *hessian_vecshaped){



}
