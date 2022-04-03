#include <stdio.h>
#include <stdlib.h>

double valueonly( int dim, double *x
);
double valueandderivatives( int dim, double *x , double* grad,
double *hessian_vecshaped
);
double * returnDomain();

double valueonly( int dim, double *x)
{
  if (dim !=2)
  {
    printf("dim is not 2, but %d\n",dim);
    exit(2);
  }
  
  double p1,p2;
  
  p1 = 0.26 * (x[0]*x[0] + x[1]*x[1]);
  p2 = 0.48 * x[0] * x[1] ;
  
  double ret = p1-p2;
  
  return ret;
}

double valueandderivatives( int dim, double *x , double* grad,
double *hessian_vecshaped)
{
  if (dim !=2)
  {
    printf("dim is not 2, but %d\n",dim);
    exit(2);
  }
    
  if (grad == NULL)
  {
    printf("valueandderivatives_beale2d: grad == NULL\n");
    exit(10);  
  }
  if (hessian_vecshaped == NULL)
  {
    printf("valueandderivatives_beale2d: hessian_vecshaped == NULL\n");
    exit(11);  
  }
  
  double ret  = valueonly( dim, x);
  
  grad[0] = 0.52*x[0] - 0.48*x[1];
  grad[1] = 0.52*x[1] - 0.48*x[0];


  //Hessian  
  hessian_vecshaped[0+2*0] = 0.52; 
  hessian_vecshaped[1+2*1] = 0.52;
  hessian_vecshaped[1+2*0] = -0.48;
  hessian_vecshaped[0+2*1] = hessian_vecshaped[1+2*0];   
                       
  return ret;
  
}

double * returnDomain(double * domain){
  domain[0] = -10;
  domain[1] = 10;

  return domain;
}

