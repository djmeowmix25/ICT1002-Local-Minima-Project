double* gradient_simple(double* x_vector[], double step, double* grad[]);
double* gradient_momentum(double* x_vector[], double step, double* grad[], double* m[], double a);



double* gradient_simple(double* x_vector[], double step, double* grad[]){
    for(int i=0; i<len(*x_vector); i++){
        *x_vector[i] = *x_vector[i] - step * (*grad[i]);
    }

    return x_vector;

}

double* gradient_momentum(double* x_vector[], double step, double* grad[], double* m[], double a){
    for(int i=0; i<len(*x_vector); i++){
        *m[i] = a * (*m[i]) + step * (*grad[i])
        *x_vector[i] = *x_vector[i] - step * (*grad[i]);
    }

    return x_vector, m;
}
