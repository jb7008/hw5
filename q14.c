/*
 * Programmer : Josh Booth      Date : Mar 22 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Approximates the value of e
 */

#include <stdio.h> /* Includes printf, scanf */
#include <math.h> /* Includes fabs, exp */

/* Threshold for the allowed difference between actual value and approximated
  value */
#define DIF_THRESHOLD 0.000001

int
main(void)
{
  int x = 0; /* Set counting variable to 0 */
  double e_approx; /* Approximation of e */

  do
  {
    x += 1; /* Increment x */
    /* Calculate e approximaition */
    e_approx = pow((2.0 * x + 1) / (2.0 * x - 1), x);
  }
  while(fabs(exp(1) - e_approx) > DIF_THRESHOLD); /* Continue while difference
    between actual and approximate is above threshold */

  /* Print results */
  printf("Converged at x = %d, %.7f, exp(1.0) = %.7f\n", x, e_approx, exp(1));
  
  return 0;
}