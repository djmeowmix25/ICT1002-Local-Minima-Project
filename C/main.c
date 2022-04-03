#include <string.h>
#include <stdio.h>
#include <ctype.h>
//#include "beale.c"
//#include "himmelblau.c"
#include "matyas.c"
//#include "algorithms.c"

// Initialise Functions
int returnInt(int dim);
int returnAlgo(int selector);
double returnStepSize(double stepSize);
double returnAlpha(double alpha);
double returnEpsilon(double epsilon);
double * returnStartingVector(int dim, double * startingVector);

// Functions
int returnInt(int dim)
{
    do
    {
        printf("Please input a dimension:\n");
        scanf("%d", &dim);
        if (dim < 2 || dim > 10)
        {
            printf("Please enter a value between 2 and 10!\n");
            continue;
        }
        else
        {
            printf("\n");
            return dim;
        }
    } while (1);
}

int returnAlgo(int selector)
{
    do
    {
        printf("Please enter an algorithm you want to use:\n");
        printf("1 : Plain Descent with K steps (uses gradient only)\n");
        printf("2 : Plain Descent with Momentum Term Alpha (uses gradient only)\n");
        printf("3 : Newtons Algorithm (uses gradient and hessian)\n");
        scanf("%d", &selector);
        printf("\n");

        if (selector < 1 || selector > 3)
        {
            continue;
        }
        else
        {
            return selector;
        }

    } while (1);
}

double returnStepSize(double stepSize)
{
    do
    {
        printf("Please enter a step size :\n");
        scanf("%lf", &stepSize);
        printf("\n");
        return stepSize;

    } while (1);
}

double returnAlpha(double alpha)
{
    do
    {
        printf("Please enter an alpha value between 0 and 1 :\n");
        scanf("%lf", &alpha);
        printf("\n");

        if (alpha < 0 || alpha > 1)
        {
            printf("Please input proper alpha value\n");
            continue;
        }
        else
        {
            return alpha;
        }
    } while (1);
}

double returnEpsilon(double epsilon)
{
    do
    {
        printf("Please enter an epsilon value between 0.01 and 0.000001 :\n");
        scanf("%lf", &epsilon);
        printf("\n");
        if (epsilon < 0.000001 || epsilon > 0.01)
        {
            printf("Please input proper epsilon value\n");
            continue;
        }
        else
        {
            return epsilon;
        }

    } while (1);
}

double * returnStartingVector(int dim, double * startingVector)
{
    for (int i = 0; i < dim; i++)
    {
        printf("Please enter starting vector value %d: \n", (i+1));
        scanf("%lf", &startingVector[i]);
        printf("\n");
    }
}

int main()
{
    // Initialise Value
    int dim = 0;
    int algoSelector = 0;
    double stepSize = 0;
    double alpha = 0;
    double epsilon = 0;

    // Initialise End

    dim = returnInt(dim);
    algoSelector = returnAlgo(algoSelector);

    if (algoSelector == 1)
    {
        stepSize = returnStepSize(stepSize);
        double domain[dim];
        double startingVector[dim];
        double fx;
        
        double *domainPtr = returnDomain(domain);
        double *startingVectorPtr = returnStartingVector(dim, startingVector);
        //fx = valueandderivatives(2, x, grad, hessian_vecshaped) //have to see how to add gradient and hessian


        printf("domain = %lf \n", domain[0]);
        printf("%d, %d, %lf", dim, algoSelector, stepSize);
    }

    else if (algoSelector == 2)
    {
        double initM[2] = {0};
        stepSize = returnStepSize(stepSize);
        alpha = returnAlpha(alpha);
        printf("%d, %d, %lf, %lf", dim, algoSelector, stepSize, alpha);
    }
    else if (algoSelector == 3)
    {
        epsilon = returnEpsilon(epsilon);
        printf("%d, %d, %lf", dim, algoSelector, epsilon);
    }
    else
    {
        printf("Error has occured!\n");
        exit(1);
    }
}
