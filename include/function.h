

#ifndef FUNCTION_H
#define FUNCTION_H

// Function structure to store info about each function
typedef struct 
{
    double (*func)(double x, void *extra); // pointer to the function
    void *extra;                           // optional data (e.g., polynomial coefficients)
    const char *name;                      // name of function for legend
    const char *color;                     // ANSI color code for plotting
} function;

// Generic function creator
function createfunc(double (*f)(double, void*), void *extra, const char *name);

#endif


