
#include <stdio.h>
#include "plot.h"
#include <math.h>

#define WIDTH 80    //total width of our graph
#define HEIGHT 25   //total height for our graph

// FUnction for ploting ASCII graph :
/*This function Draw the graph for multiple function insode a fixed 2D grid of characters 
It plots the X-Y axes at many sample points then draw the curve of a function using colored star characters.
it can also plot multiple functions at once */


void plot(function functions[], int count, double xmin, double xmax)
{
    char grid[HEIGHT][WIDTH]; //stores the Ascii charactrers
    int owner [HEIGHT][WIDTH]; //stores index of function ownning each star

    //1. clear grid
    //INitialise everything to blank space
    for (int i=0; i<HEIGHT; i++)
      for(int j=0; j<WIDTH; j++){
        grid[i][j]= ' ';
        owner[i][j]= -1;}


    //2. set axes positions
    int yaxis= WIDTH/2;  //vertical axis
    int xaxis= HEIGHT/2; //horizontal axis

    for (int col=0; col<WIDTH; col++)
         grid[xaxis][col]='-';  //this is for x axis

     for (int row=0; row<HEIGHT; row++)
     grid[row][yaxis]='|';    //this is for making y axis

     //3. plot functions

    double ymin = -2, ymax = 2; //y-range of graph

// oversampling for smoother curves,
// it means more x points than grid columns so curve looks smooth
int samples = WIDTH * 6;  // 6× more horizontal points

//loop over each function entered by user
for (int f = 0; f < count; f++)
{
    for (int s = 0; s < samples; s++) //evaluate each function at many point
    {
        //convert sample indexes to x values from xmin to xmax
        double t = (double)s / samples;
        double x = xmin + t * (xmax - xmin);
        
        //calling function pointer to get y value
        double y = functions[f].func(x, functions[f].extra);

        if (y < ymin || y > ymax)   //to skip point outside our range
            continue;

        //x to comlumn in grid
        int col = (int)(t * (WIDTH - 1));

        // Choose row based on y
        int row = (int)((y - ymin) / (ymax - ymin) * (HEIGHT - 1));
        row = HEIGHT - 1 - row;

        if (grid[row][col] == ' ')
        {
            grid[row][col] = '*';
            owner[row][col] = f;
        }
    }
}
       //4.print the grid with colors
       //wherever we find *, we print color from correct function color
       for(int row = 0; row<HEIGHT; row++)
       {
         for(int col=0; col<WIDTH; col++)
         {
            if(grid[row][col]== '*' && owner[row][col] != -1)
            {
                int f = owner[row][col];  //function index
                printf("%s*\033[0m",functions[f].color);   //colored star
            }
             else 
             putchar(grid[row][col]);
         }   
        putchar('\n');
       }
         
 //5. print graph with function name
 printf("\nFunctions: \n");
 for(int f=0; f<count; f++)
      printf("%s %s\033[0m\n", functions[f].color,functions[f].name);
}