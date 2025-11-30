
#include <stdio.h>
#include "plot.h"
#include <math.h>

#define WIDTH 80
#define HEIGHT 25

//plot ASCII graph with axes having origin 

void plot(function functions[], int count, double xmin, double xmax)
{
    char grid[HEIGHT][WIDTH];
    int owner [HEIGHT][WIDTH];

    //1. clear grid
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

    double ymin = -2, ymax = 2;

// Increase sampling for smoothness
int samples = WIDTH * 6;  // 6× more points

for (int f = 0; f < count; f++)
{
    for (int s = 0; s < samples; s++)
    {
        double t = (double)s / samples;
        double x = xmin + t * (xmax - xmin);

        double y = functions[f].func(x, functions[f].extra);

        if (y < ymin || y > ymax)
            continue;

        // Choose a column based on x
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
       //4.print the grid
       for(int row = 0; row<HEIGHT; row++)
       {
         for(int col=0; col<WIDTH; col++)
         {
            if(grid[row][col]== '*' && owner[row][col] != -1)
            {
                int f = owner[row][col];
                printf("%s*\033[0m",functions[f].color);
            }
             else 
             putchar(grid[row][col]);
         }
              
        putchar('\n');
       }
         
 //5. print graph name
 printf("\nFunctions: \n");
 for(int f=0; f<count; f++)
      printf("%s %s\033[0m\n", functions[f].color,functions[f].name);
}