/*
 * Programmer : Josh Booth      Date : Mar 22 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Calculates and displays different ways of finding a straight line
 */

#include <stdio.h> /* Includes printf, scanf */

int get_problem(void); /* Gets method to solve for line */
/* Gets two x, y  coordinates */
void get2_pt(float *x1, float *y1, float *x2, float *y2);
/* Gets x, y coordinate and slope */
void get_pt_slope(float *x1, float *y1, float *slope);
/* Returns slope and y_intercept from two points */
void slope_intcpt_from2_pt(float x1, float y1, float x2, float y2,
  float *slope, float *y_intercept);
/* Returns y_intercept from point_slope form */
float intcpt_from_pt_slope(float x1, float y1, float slope);
/* Displays the two_point line equation with a heading */
void display2_pt(float x1, float y1, float x2, float y2);
/* Displays point_slope line equation with a heading */
void display_pt_slope(float x1, float y1, float slope);
/* Displays the slope_intercept line equation with a heading */
void display_slope_incpt(float slope, float y_intercept);


int
main(void)
{
  int form_choice, /* Checks if program should use point slope form or slope
    intercept */
    loop_program; /* Flags to keep the programming looping until user wants to
    exit */
  char run_again; /* Gets user input if program should run again */
  float x1,
    x2,
    y1,
    y2,
    slope,
    y_intercept;

  loop_program = 1; /* Sets the program to initially loop */
  while( loop_program )
  {
    form_choice = get_problem(); /* Gets method to solve for line */
    switch(form_choice)
    {
      case 1:
        get2_pt(&x1, &y1, &x2, &y2); /* Gets two x, y pairs */
        printf("\n"); /* Newline for formatting */

        /* Returns slope and y-intercept from two points */
        slope_intcpt_from2_pt(x1, y1, x2, y2, &slope, &y_intercept);

        /* Displays the two-point line equation with a heading */
        display2_pt(x1, y1, x2, y2);
        printf("\n"); /* Prints newline for formatting */
        
        /* Displays the slope-intercept line equation with a heading */
        display_slope_incpt(slope, y_intercept);

        break;
      case 2:
        get_pt_slope(&x1, &y1, &slope); /* Gets x, y coordinate and slope */
        printf("\n"); /* Newline for formatting */

        /* Returns y-intercept from point-slope form */
        y_intercept = intcpt_from_pt_slope(x1, y1, slope);

        /* Displays point-slope line equation with a heading */
        display_pt_slope(x1, y1, slope);
        printf("\n"); /* Newline for formatting */

        /* Displays the slope-intercept line equation with a heading */
        display_slope_incpt(slope, y_intercept);

        break;
    }
    /* Checks if program should loop again */
    printf("Do another conversion (Y or N) => ");
    getchar(); /* Clears newline from buffer */
    scanf("%c", &run_again);
    if(run_again == 'N')
    {
      loop_program = 0;
    }
    else
    {
      loop_program = 1;
    }
  }

  return 0;
}


/* Gets input choice */
int get_problem(void)
{
  int form_choice; /* Checks if program should use point slope form or slope
    intercept */

  printf("Select the form that you would like to convert to "
         "slope-intercept form:\n");
  printf("1) Two-point form\n");
  printf("2) Point-slope\n");
  printf("=>");
  scanf("%d", &form_choice); /* Gets users choice */

  return(form_choice); /* Returns users choice */

}

/* Gets two x, y  coordinates */
void
get2_pt(float *x1, float *y1, float *x2, float *y2)
{
  /* Stores coordinates in pointers */
  printf("Enter the x-y coordinates for first point: ");
  scanf("%f %f", x1, y1);
  printf("Enter the x-y coordinates for second point: ");
  scanf("%f %f", x2, y2);

}

/* Gets x, y coordinate and slope */
void
get_pt_slope(float *x1, float *y1, float *slope)
{
  /* Stores coordinates in pointers */
  printf("Enter the x-y coordinates of a point: ");
  scanf("%f %f", x1, y1);

  /* Stores slope in pointers */
  printf("Enter the slope: ");
  scanf("%f", slope);

}

/* Returns slope and y_intercept from two points */
void
slope_intcpt_from2_pt(float x1, float y1, float x2, float y2, 
  float *slope, float *y_intercept)
{
  *slope = (y2 - y1) / (x2 - x1); /* Calculates slope in pointer */
  *y_intercept = y1 - (*slope * x1); /* Calculates y_intercept in pointer */
}

/* Returns y_intercept from point_slope form */
float
intcpt_from_pt_slope(float x1, float y1, float slope)
{
  return(y1 - (slope * x1));
}

/* Displays the two_point line equation with a heading */
void
display2_pt(float x1, float y1, float x2, float y2)
{
  printf("Two-point form\n");
  printf("    (%.2f - %.2f)\n", y2, y1);
  printf("m = ----------------\n");
  printf("    (%.2f - %.2f)\n", x2, x1);
}

/* Displays point_slope line equation with a heading */
void
display_pt_slope(float x1, float y1, float slope)
{
  printf("Point-slope form\n");
  printf("y - %.2f = %.2f(x - %.2f)\n", y1, slope, x1);
}

/* Displays the slope_intercept line equation with a heading */
void
display_slope_incpt(float slope, float y_intercept)
{
  printf("Slope-intercept form\n");
  printf("y = %.2fx + %.2f\n", slope, y_intercept);
}
