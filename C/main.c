#include <string.h>
#include <stdio.h>
#include <ctype.h>
//#include "beale.c"
//#include "himmelblau.c"
#include "matyas.c"
#include "algorithms.c"


//Initialise Functions
int returnInt(int dim);
int returnAlgo(int selector);


//Functions
int returnInt (int dim){
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
            return dim;
        }
    }while(1);
}

int returnAlgo (int selector){
    do
    {
        printf("Please enter an algorithm you want to use:\n");
        printf("1 : Plain Descent with K steps (requires gradient only)\n");
        printf("2 : Plain Descent with Momentum Term Alpha (requires gradient only)\n");
        printf("Please enter an algorithm you want to use:\n");


        scanf("%d", &selector);

    }while(1);
}


int main()
{   
    //Initialise Value
    int dim = 0;

    //Initialise End

    dim = returnInt(dim);

}

