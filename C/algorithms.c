#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>



void gradient_simple(double *x, double step, double *grad, int dim){
    //unsigned int size = sizeof(x) / sizeof(x[0]);

    for(int i = 0; i < dim; i++){
        x[i] = x[i] - step * (grad[i]);
    }
}

void gradient_momentum(double *x, double *m, double step, double *grad, double al, int dim){

    for(int i = 0; i < dim; i++){
        m[i] = al * (m[i]) + step * (grad[i]);
        x[i] = x[i] - m[i];
    }
}

// void gradient_newton(double *x, double step, double *grad, double *hessian_vecshaped){



// }
