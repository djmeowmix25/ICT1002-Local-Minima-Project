#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/* TEST FUNCTIONS AVAILABLE */
// beale2d     boundary: -4.5 4.5 | minima: 3 0.5
// himmelblau  boundary: -5 5 | minima: 3 2 , -2.805 3.13, -3.779 -3.283 , 3.584 -1.848
// twominima   boundary: -1 1 | minima: 0.5 0.5 , 0 0
// matyas      boundary: -10 10 | minima: 0 0

/* PUT OTHER FUNCTION FILES UNDER functions/ FOLDER, INCLUDE FILE WHEN COMPILING */
/* e.g. gcc -Wall functions/beale2d.c main.c -o main */
#include "functions/function.h"
#include "algorithms.c"
#include "linspace.c"

#define BUFFER_SIZE 4096

// Function declarations
int getDim();
int getAlgo();
int getRounds();
double getStep();
double getMomentum();
double getEpsilon();
bool parse_int(char *string, int *integer);
void getDomain(double *domain);
void getStartingVector(int dim, double *domain, double *startingVector);
int checker(double *x, double *domain, double *grad, int dim);

// Functions
// Validation for integer input
bool parse_int(char *string, int *integer)
{
    // Check for whitespace
    int i = 0;
    while (isspace(string[i]))
    {
        i++;
    }
    int length = strlen(string);

    if (length == i)
    {
        return false;
    }
    char integer_buffer[BUFFER_SIZE];
    int integer_chars = 0;

    // If negative integer, got dash -
    if (string[i] == '-')
    {
        integer_buffer[integer_chars] = '-';
        integer_chars++;
        i++;

        if (!isdigit(string[i]))
        {
            return false;
        }
    }

    while (i < length && !isspace(string[i]))
    {
        if (!isdigit(string[i]))
        {
            return false;
        }

        integer_buffer[integer_chars] = string[i];
        integer_chars++;
        i++;
    }

    integer_buffer[integer_chars] = '\0';

    while (isspace(string[i]))
    {
        i++;
    }

    if (string[i] != '\0')
    {
        return false;
    }
    *integer = atoi(integer_buffer);

    return true;
}

int getDim()
{
    char buffer[BUFFER_SIZE];
    int status;
    int dim = 0;
    bool parsed_correct = true;
    do
    {
        printf("Please input a dimension:\n");
        // status = scanf("%d", &dim);
        fgets(buffer, BUFFER_SIZE, stdin);
        parsed_correct = parse_int(buffer, &dim);
        if (parsed_correct != 1)
        {
            printf("ERROR: Please enter an integer!\n");
            parsed_correct = false;
        }
        else if (dim < 2 || dim > 10)
        {
            printf("ERROR: Please chose a value between 2 and 10\n");
            parsed_correct = false;
        }
        else
        {
            printf("\n");
            return dim;
        }
    } while (!parsed_correct);
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

int getRounds()
{
    int status;
    int rounds;
    do
    {
        printf("Please input number of rounds for algorithm to run ");
        printf("(type 0 to use threshold instead):\n");
        status = scanf("%d", &rounds);

        if (status != 1)
        {
            printf("ERROR: Please enter an integer!\n");
        }
        else if (rounds < 0)
        {
            printf("ERROR: Please chose a value more than 0\n");
        }
        else
        {
            printf("\n");
            return rounds;
        }
    } while (1);
}

double getThreshold()
{
    int status;
    double threshold;
    do
    {
        printf("Please input threshold for algorithm to terminate:\n");
        status = scanf("%lf", &threshold);

        if (status != 1)
        {
            printf("ERROR: Please enter a real number!\n");
        }
        else
        {
            printf("\n");
            return threshold;
        }
    } while (1);
}

double getStep()
{
    int status;
    double step;
    do
    {
        printf("Recommended step size is between 0.1 to 0.00001\n");
        printf("Please enter a step size:\n");
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
        printf("Please enter an epsilon value between 0.01 and 0.0000001 :\n");
        status = scanf("%lf", &epsilon);
        printf("\n");

        if (status != 1)
        {
            printf("ERROR: Please enter a real number\n");
        }
        else if (epsilon < 0.0000001 || epsilon > 0.01)
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
        do
        {
            printf("Please enter starting vector value x%d: \n", (i + 1));
            status = scanf("%lf", &startingVector[i]);
            printf("\n");

            if (status != 1)
            {
                printf("ERROR: Please enter a real number\n");
            }
            else if (startingVector[i] < domain[0] || startingVector[i] > domain[1])
            {
                printf("ERROR: Value higher than specified domain of [%lf, %lf]\n",
                       domain[0], domain[1]);
            }
            else
            {
                break;
            }
        } while (1);
    }
}

int checker(double *x, double *domain, double *grad, int dim)
{
    int counter = 0;
    for (int i = 0; i < dim; i++)
    {
        if (x[i] <= domain[0])
        {
            counter = counter + 1;
            if (grad[i] > 0)
            {
                printf("TERMINATED: x hit lower domain\n");
                return 1;
            }
        }
        else if (x[i] >= domain[1])
        {
            counter = counter + 1;
            double tempGrad = -1 * grad[i];
            if (tempGrad > 0)
            {
                printf("TERMINATED: x hit upper domain\n");
                return 1;
            }
        }
    }
    if (counter >= 2)
    {
        printf("TERMINATED: Two or more x values hit domain\n");
        return 1;
    }
    return 0;
}

int main()
{
    // Initialise Value
    int dim;
    int algoSelector;
    int count = 0;
    int rounds;
    int check;
    double threshold = -999999;
    double domain[2];
    double stepSize;
    double al;
    double epsilon;
    FILE *fs = fopen("steps.txt", "w");
    FILE *f3d = fopen("3d.txt", "w");
    double xLinArr[50]; // array used to store x values after linspace

    double fx;
    double *x;
    double *grad;
    double *hessian_vecshaped;
    // Initialise End

    // Get common user-set parameters (dimension, domain, algorithm)
    dim = getDim();
    getDomain(domain);
    algoSelector = getAlgo();
    rounds = getRounds();
    if (rounds == 0)
    {
        threshold = getThreshold();
    }

    // Allocate memory for arrays used for algorithm
    x = (double *)malloc(dim * sizeof(double));
    grad = (double *)malloc(dim * sizeof(double));
    hessian_vecshaped = (double *)malloc(dim * dim * sizeof(double));

    // initialize M array for algorithm 2, initialize with 0 values
    double *mArr = (double *)malloc(dim * sizeof(double));
    for (int i = 0; i < dim; i++)
    {
        mArr[i] = 0;
    }

    // Get starting vector
    getStart(dim, domain, x);

    // Get algorithm specific user-set parameters (step size, momentum, epsilon)
    switch (algoSelector)
    {
    case 1:
        stepSize = getStep();
        break;
    case 2:
        stepSize = getStep();
        al = getMomentum();
        break;
    case 3:
        epsilon = getEpsilon();
        break;
    default:
        printf("Error has occured!\n");
        exit(1);
    }

    // Loop and run algorithms
    while (1)
    {
        fx = valueandderivatives(dim, x, grad, hessian_vecshaped);
        // Run algorithm based on choice
        switch (algoSelector)
        {
        case 1:
            gradient_simple(x, stepSize, grad, dim);
            break;
        case 2:
            gradient_momentum(x, mArr, stepSize, grad, al, dim);
            break;
        case 3:
            gradient_newton(x, grad, hessian_vecshaped, epsilon, dim);
            break;
        default:
            printf("Error has occured!\n");
            exit(1);
        }
        check = checker(x, domain, grad, dim); // Check if x within domain
        count++;
        // Termination conditions
        if (count == rounds)
        {
            printf("TERMINATED: reach round limit of %d\n", rounds);
            break;
        }
        if (fx <= threshold)
        {
            printf("TERMINATED: reach threshold of %lf\n", threshold);
            break;
        }
        if (check == 1)
        {
            // reached domain boundary
            break;
        }
        // Print x values
        for (int i = 0; i < dim; i++)
        {
            if (i == 0)
            {
                printf("[%lf, ", x[i]);
            }
            else if (i == dim - 1)
            {
                printf("%lf] = %lf\n", x[i], fx);
            }
            else
            {
                printf("%lf, ", x[i]);
            }
        }
        // Output to steps.txt if dim = 2
        if (dim == 2)
        {
            fprintf(fs, "%lf,%lf,%lf\n", x[0], x[1], fx); // write to file
        }
    }
    // Print local minima (last x values)
    printf("Local minima is near ");
    for (int i = 0; i < dim; i++)
    {
        if (i == 0)
        {
            printf("[%lf, ", x[i]);
        }
        else if (i == dim - 1)
        {
            printf("%lf]\n", x[i]);
        }
        else
        {
            printf("%lf, ", x[i]);
        }
    }
    fclose(fs);

    // Generate values for plotting surface diagram in matplotlib
    if (dim == 2)
    {
        linspace(domain[0], domain[1], 50, xLinArr);
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                x[0] = xLinArr[j];
                x[1] = xLinArr[i];
                fprintf(f3d, "%lf,%lf,%lf\n", xLinArr[j], xLinArr[i], valueonly(2, x)); // write to file
            }
        }
        printf("NOTICE:\n3d.txt contains values for plotting surface diagram in matplotlib\n");
        printf("steps.txt contains values for path taken by algorithm\n");
        printf("Run visualization.py to visualize the data with matplotlib\n");
    }
    fclose(f3d);
}
