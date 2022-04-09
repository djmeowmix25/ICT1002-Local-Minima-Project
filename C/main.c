#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>




/* CHOOSE 1 FUNCTION TO RUN FOR PROGRAM */
#include "functions/beale2d.h"
//#include "functions/himmelblau.h"
//#include "functions/twominima.h"
//#include "functions/matyas.h"

#include "algorithms.h"

// Function declarations
int getDim();
int getAlgo();
double getStep();
double getMomentum();
double getEpsilon();
void getDomain(double *domain);
void getStartingVector(int dim, double *domain, double *startingVector);

// Functions
int getDim()
{
    int status;
    int dim;
    do
    {
        printf("Please input a dimension:\n");
        status = scanf("%d", &dim);

        if (status != 1)
        {
            printf("ERROR: Please enter an integer!\n");
        }
        else if (dim < 2 || dim > 10)
        {
            printf("ERROR: Please chose a value between 2 and 10\n");
        }
        else
        {
            printf("\n");
            return dim;
        }
    } while (1);
}

int getAlgo()
{
    int status;
    int selector;
    do
    {
        printf("Please choose an algorithm you want to use:\n");
        printf("1 : Plain Descent with K steps\n");
        printf("2 : Plain Descent with Momentum Term Alpha\n");
        printf("3 : Newtons Algorithm\n");
        status = scanf("%d", &selector);
        printf("\n");

        if (status != 1)
        {
            printf("ERROR: Please enter an integer\n");
        }
        else if (selector < 1 || selector > 3)
        {
            printf("ERROR: Please choose either 1, 2 or 3\n");
        }
        else
        {
            return selector;
        }

    } while (1);
}

double getStep()
{
    int status;
    double step;
    do
    {
        printf("Recommended step size is between 0.1 to 0.0001\n");
        printf("Please enter a step size :\n");
        status = scanf("%lf", &step);
        printf("\n");

        if (status != 1)
        {
            printf("ERROR: Please enter a real number\n");
        }
        else
        {
            return step;
        }

    } while (1);
}

double getMomentum()
{
    int status;
    double al;
    do
    {
        printf("Please enter a momentum term value between 0 and 1 :\n");
        status = scanf("%lf", &al);
        printf("\n");

        if (status != 1)
        {
            printf("ERROR: Please enter a real number\n");
        }
        else if (al <= 0 || al >= 1)
        {
            printf("ERROR: Please input proper momentum term value\n");
        }
        else
        {
            return al;
        }
    } while (1);
}

double getEpsilon()
{
    int status;
    double epsilon;
    do
    {
        printf("Please enter an epsilon value between 0.01 and 0.000001 :\n");
        status = scanf("%lf", &epsilon);
        printf("\n");

        if (status != 1)
        {
            printf("ERROR: Please enter a real number\n");
        }
        else if (epsilon < 0.000001 || epsilon > 0.01)
        {
            printf("ERROR: Please input proper epsilon value\n");
        }
        else
        {
            return epsilon;
        }

    } while (1);
}

void getDomain(double *domain)
{
    double status1;
    double status2;
    do
    {
        printf("Please enter the domain inclusive from: \n");
        status1 = scanf("%lf", &domain[0]);
        printf("Please enter the domain inclusive to: \n");
        status2 = scanf("%lf", &domain[1]);
        printf("\n");

        if (status1 != 1 || status2 != 1)
        {
            printf("ERROR: Please enter integers\n");
        }
        else if (domain[0] > domain[1])
        {
            printf("ERROR: From number higher than to number\n");
        }
        else
        {
            break;
        }
    } while (1);
}

void getStart(int dim, double *domain, double *startingVector)
{
    int status;
    for (int i = 0; i < dim; i++)
    {
        do {
          printf("Please enter starting vector value x%d: \n", (i+1));
          status = scanf("%lf", &startingVector[i]);
          printf("\n");

          if (status != 1)
          {
              printf("ERROR: Please enter a real number\n");
          }
          else if (startingVector[i] < domain[0] || startingVector[i] > domain[1])
          {
              printf("ERROR: Value higher than specified domain of [%d, %d]\n",
              domain[0], domain[1]);
          }
          else
          {
              break;
          }
        } while(1);
    }
}
// define checker in C
// def checker (x, domain, grad):
//     counter = 0
//     for i in range(len(x)):
//         if x[i] <= domain[0]:
//             counter+=1
//             if grad[i] > 0:
//                 print("Terminated x hit lower domain")
//                 exit()
//
//         elif x[i] >= domain[1]:
//             counter+=1
//             tempGrad = -1 * grad[i]
//             if tempGrad > 0:
//                 print("Terminated x hit upper domain")
//                 exit()
//     if counter >=2:
//         print("Two or more")
//         exit()

int main()
{
    // Initialise Value
    int dim;
    int algoSelector;
    double domain[2];
    double stepSize;
    double al;
    double epsilon;

    double fx;
    double* x;
    double* grad;
    double* hessian_vecshaped;
    // Initialise End

    // Get common user-set parameters (dimension, domain, algorithm)
    dim = getDim();
    getDomain(domain);
    getStart(dim, domain, x);
    algoSelector = getAlgo();
    // ask for limit (no. of rounds for algo to run)

    // Allocate memory for array containing x values
    x = (double*) malloc(dim * sizeof(double));
    grad = (double*) malloc(dim * sizeof(double));
    hessian_vecshaped = (double*) malloc(dim*dim * sizeof(double));

    // Run gradient descent algorithms
    if (algoSelector == 1)
    {
        stepSize = getStep();
        int counter = 1 ;
        while(counter == 1){
            fx = valueandderivatives(2, x, grad, hessian_vecshaped);
            gradient_simple(x, stepSize, grad);

            printf("x1:%lf x2:%lf grad%lf fx:%lf \n", x[0], x[1], grad[0], fx );
            sleep(1);
        }

        // printf("domain = %lf \n", domain[0]);
        // printf("%d, %d, %lf", dim, algoSelector, stepSize);
    }
    else if (algoSelector == 2)
    {
        stepSize = getStep();
        //al = getMomentum();
        // double initM[2] = {0};
        // initialize M for algorithm, calloc allocates 0 filled array
        //double* mArr = (double*) calloc(dim * sizeof(double));

        printf("%d, %d, %lf, %lf", dim, algoSelector, stepSize, al);
    }
    else if (algoSelector == 3)
    {
        epsilon = getEpsilon();
        printf("%d, %d, %lf", dim, algoSelector, epsilon);
    }
    else
    {
        printf("Error has occured!\n");
        exit(1);
    }

    // while below limit or never hit edge
    //fx = valueandderivatives(2, x, grad, hessian_vecshaped) //have to see how to add gradient and hessian
}
