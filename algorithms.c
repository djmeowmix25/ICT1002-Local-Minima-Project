#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "inverter.c"

void gradient_simple(double *x, double step, double *grad, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        x[i] = x[i] - step * (grad[i]);
    }
}

void gradient_momentum(double *x, double *m, double step, double *grad, double al, int dim)
{

    for (int i = 0; i < dim; i++)
    {
        m[i] = al * (m[i]) + step * (grad[i]);
        x[i] = x[i] - m[i];
    }
}

void gradient_newton(double *x, double *grad, double *hessian_vecshaped, double epsilon, int dim)
{
    double idMatrix[dim * dim];
    double matrix[dim * dim];
    double matrixArray[dim][dim];
    double result[dim];
    for (int i = 0; i < dim*dim; i++)
    {
        idMatrix [i] = 0;
    }

    for (int i = 0; i < dim; i=i+(dim+1))
    {
        idMatrix[i] = 1;
    }

    for (int i = 0; i < dim * dim; i++)
    {
        matrix[i] = hessian_vecshaped[i] + epsilon * idMatrix[i];
    }

    inverter_function(dim, matrix);

    int k = 0;
    for (int i = 0; i < dim ; i++)
    {
        for (int j = 0 ; j<dim ; j++){
            matrixArray[i][j] = matrix[k];
            k = k+1;
        }
    }

    for (int i = 0; i < dim ; i++)
    {
        for (int j = 0 ; j<dim ; j++){
            result[i] = result[i] + matrixArray[i][j] * grad[j];
        }
    }

    for (int i=0; i<dim; i++){
        x[i] = x[i] - result[i];
    }
}
