#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "function.h"
#include "plot.h"

/*the wrapper functions for trigonometric functions:

we need wrappers because  our generic function pointer has the format
 to receive extra parameters too but some function dont have extra parameters

 so we kind of wrap them inside small functions ignoring the extra parameter*/

double sinwrapper( double x, void *extra)
 {return sin(x); }
 double coswrapper( double x, void *extra)
 {return cos(x); }
 double tanwrapper( double x, void *extra)
 {return tan(x); }
 double expwrapper( double x, void *extra)
 {return exp(x) / 50.0; }

 
 //polynomial wrapper
 double polywrapper(double x, void *extra)
 {
    
    int degree = *(int*)extra;

    if (degree == 1) return x;  //linear function
    if (degree == 2) return x*x; //quadratic function
    if (degree == 3) return x*x*x; //Cubic function
    
    return x;
 }

   int main()
{
    srand(time(NULL)); //to initalise random colors generation
     
    //input number of functions user want
    int numfn;
    printf("How many functions do you want to plot? ");
    scanf("%d", &numfn);

 if(numfn <=0 || numfn>10)
 {
    printf("INvalid number of functions");
    return 1;
 }
   
 /*ARRAY OF FUNCTION STRUCTURE:
    this is used to store all the functions user chooses and their datas 
    stored in structure */

   function functions[10];  
    
   for(int i=0; i<numfn; i++)
 {
   //input the choice of function from user
    printf("\nFunctions %d: \n", i+1);
    printf("1. sin(x)\n2. cos(x)\n3. tan(x)\n4. exponential\n5.polynomial\nChoose a Number: ");
    int choice;
    scanf("%d", &choice);
   
    //decide the function based on what user chose
    if(choice == 1)
       functions[i]=createfunc(sinwrapper, NULL, "sin(x)"); 
    else if(choice == 2)
       functions[i]=createfunc(coswrapper, NULL, "cos(x)");
    else if(choice == 3)
       functions[i]=createfunc(tanwrapper, NULL, "tan(x)");
       else if(choice == 4)
       functions[i]=createfunc(expwrapper, NULL, "e^x");

    else if(choice == 5)
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