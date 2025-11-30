#ifndef PLOT_H
#define PLOT_H

/*this header file simply provides the function declaration that our plotting
function would require*/
#include "function.h"

 /*PARAMETERS:
 FUNCTION ARRAY  to have list of functions that must be plotted
 count takes how many functions are passed 
 xmin and xmax takes the range of x values*/

void plot(function functions[], int count, double xmin, double xmax);

#endif