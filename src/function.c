
#include "function.h"
#include <stdlib.h>

// this array has list of ANSI terminal colors that we are going to use for the functions
static const char *colors[] = 
{
    "\033[31m",  //red
    "\033[32m", //green
    "\033[33m",  //yellow
    "\033[34m",  //blue
    "\033[35m", //magenta
};
static int nxtClrIndex = 0; //to keep track of colors given to function

//this function created and return a fully prepared function with all the information
function createfunc(double (*f)(double, void*), void *extra, const char *name)
 {
    function fn;
    fn.func = f;    //points to actual mathematical function
    fn.extra = extra;   //any additional data that function might require
    fn.name = name;   //to give name to the function so we can print it later
    fn.color = colors[nxtClrIndex++ % 6];  // cycle through colors
    return fn;
}