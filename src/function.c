
#include "function.h"
#include <stdlib.h>

// List of ANSI colors
static const char *colors[] = 
{
    "\033[31m", "\033[32m", "\033[33m",
    "\033[34m", "\033[35m", "\033[36m"
};
static int nextColorIndex = 0;

// Create a GraphFunction with random color (no repeats until all used)
function createfunc(double (*f)(double, void*), void *extra, const char *name) {
    function fn;
    fn.func = f;
    fn.extra = extra;
    fn.name = name;
    fn.color = colors[nextColorIndex++ % 6]; // cycle through colors
    return fn;
}