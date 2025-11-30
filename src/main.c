#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "function.h"
#include "plot.h"

//wrapper functions for trig
double sinwrapper( double x, void *extra)
 {return sin(x); }
 double coswrapper( double x, void *extra)
 {return cos(x); }
 double tanwrapper( double x, void *extra)
 {return tan(x); }
 
 //polynomail wrapper
 double polywrapper(double x, void *extra)
 {
    
    int degree = *(int*)extra;

    if (degree == 1) return x;
    if (degree == 2) return x*x;
    if (degree == 3) return x*x*x;

    return x;
 }

   int main()
{
    srand(time(NULL)); //to initalise random colors generation
     
    int numfn;
    printf("How many functions do you want to plot? ");
    scanf("%d", &numfn);

 if(numfn <=0 || numfn>10)
 {
    printf("INvalid number of functions");
    return 1;
 }

   function functions[10];  //array to store all kind of functions
    
   for(int i=0; i<numfn; i++)
 {
    printf("\nFunctions %d: \n", i+1);
    printf("1. sin(x)\n2. cos(x)\n3. tan(x)\n4. polynomial\nChoose: ");
    int choice;
    scanf("%d", &choice);
   
    if(choice == 1)
       functions[i]=createfunc(sinwrapper, NULL, "sin(x)");
    else if(choice == 2)
       functions[i]=createfunc(coswrapper, NULL, "cos(x)");
    else if(choice == 3)
       functions[i]=createfunc(tanwrapper, NULL, "tan(x)");
    else if(choice == 4)
    {
        static int degree;   // static so pointer remains valid
    printf("Enter degree (1-3): ");
    scanf("%d", &degree);

    if (degree < 1 || degree > 3)
    {
        printf("Invalid degree. Using 2.\n");
        degree = 2;
    }

    functions[i] = createfunc(polywrapper, &degree, "polynomial");
    }

    else{
        printf("invalid choice. Using sin(x) by default.\n");
        functions[i]=createfunc(sinwrapper, NULL,"sin(x)");
    }
 }

 //plot from x=-10 to x=10
   
 plot(functions,numfn,-10,10);



      return 0;
}