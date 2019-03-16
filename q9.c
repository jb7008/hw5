/*
 * Programmer : Josh Booth      Date : Mar 22 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Calculate the drag force given A and CD
 */

#include <stdio.h> /* Includes printf, scanf */

#define GAS_DENSITY 1.23 /* Density of gas vehciles travels through (kg/m^3) */

/* Calculate drag force */
float calc_drag(int area, int velocity, float drag_coefficient);

int
main(void)
{
  int area; /* Area of the vehicle */
  float drag_coefficient; /* Drag coefficient */

  /* Get variables from user */
  printf("Enter drag coefficient: ");
  scanf("%f", &drag_coefficient);
  printf("Enter area: ");
  scanf("%d", &area);

  /* Table heading */
  printf("-------------------------------\n");
  printf("Velocity             Drag\n");
  printf("-------------------------------\n");
  /* Interates through the drag forces with velocity 0-40 in increments of 5 */
  for(int i = 0; i <= 40; i += 5)
  {
    printf("%-20.2f%.3f\n", (float)i, calc_drag(area, i, drag_coefficient));
  }
  /* Table ending */
  printf("-------------------------------\n");

  return 0;
}

/* Calculate drag force */
float
calc_drag(int area, int velocity, float drag_coefficient)
{
  /* Calculates drag force using equation F = 1/2 * CD * A * p * V^2 */
  return((1/2.0) * drag_coefficient * area * GAS_DENSITY 
    * velocity * velocity);
}