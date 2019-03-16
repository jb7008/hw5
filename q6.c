/*
 * Programmer : Josh Booth      Date : Mar 22 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Solve a simple conduction problem when a variable is missing
 */

#include <stdio.h> /* Includes printf, scanf */

/* Receieves input variables from user */
void get_variables(float *heat_transfer, float *thermal_conductivity,
  float *area, float *temp_one_side, float *temp_other_side, 
  float *conductor_thickness);
/* Displays all variables after calculating missing one */
void display_variables(float heat_transfer, float thermal_conductivity,
  float area, float temp_one_side, float temp_other_side, 
  float conductor_thickness);
/* Finds different missing variables using variations of the formula
  H = (kA( T2 - T1 )) /  */
/* Finds heat transfer */
float calc_h(float thermal_conductivity, float area, float temp_one_side,
  float temp_other_side, float conductor_thickness);
/* Finds coefficient of thermal conductivity */
float calc_k(float heat_transfer, float area, float temp_one_side,
  float temp_other_side, float conductor_thickness);
/* Finds cross-sectional area */
float calc_a(float heat_transfer, float thermal_conductivity,
  float temp_one_side, float temp_other_side, float conductor_thickness);
/* Finds temperature of one side */
float calc_t1(float heat_transfer, float thermal_conductivity,
  float area, float temp_other_side, float conductor_thickness);
/* Finds temperature of other side */
float calc_t2(float heat_transfer, float thermal_conductivity,
  float area, float temp_one_side, float conductor_thickness);
/* Finds thickness of the conductor */
float calc_c(float heat_transfer, float thermal_conductivity, float area,
  float temp_one_side, float temp_other_side);

int
main(void)
{
  float heat_transfer, /* Rate of heat transfer (watts) */
  thermal_conductivity, /* Coefficient of thermal conductivity (W / m - K) */
  area, /* Cross_sectional area of conductor: (W^2) */
  temp_one_side, /* Temperature on one side (K) */
  temp_other_side, /* Temperature on other side (K) */
  conductor_thickness; /* Thickness of conductor (m) */

  /* Receieves input variables from user */
  get_variables(&heat_transfer, &thermal_conductivity, &area, &temp_one_side,
    &temp_other_side, &conductor_thickness);

  /* Finds missing variable if it was flagged as missing */
  if(heat_transfer == -1)
  {
    heat_transfer = calc_h(thermal_conductivity, area, temp_one_side,
      temp_other_side, conductor_thickness);
  }
  else if(thermal_conductivity == -1)
  {
    thermal_conductivity = calc_k(heat_transfer, area, temp_one_side,
      temp_other_side, conductor_thickness);
  }
  else if(area == -1)
  {
    area = calc_a(heat_transfer, thermal_conductivity, temp_one_side,
      temp_other_side, conductor_thickness);
  }
  else if(temp_one_side == -1)
  {
    temp_one_side = calc_t1(heat_transfer, thermal_conductivity, area,
      temp_other_side, conductor_thickness);
  }
  else if(temp_other_side == -1)
  {
    temp_other_side = calc_t2(heat_transfer, thermal_conductivity, area,
      temp_one_side, conductor_thickness);
  }
  else if(conductor_thickness == -1)
  {
    conductor_thickness = calc_c(heat_transfer, thermal_conductivity, area,
      temp_one_side, temp_other_side);
  }
  /* Displays all variables after calculating missing one */
  display_variables(heat_transfer, thermal_conductivity, area, temp_one_side,
    temp_other_side, conductor_thickness);

  return 0;
}

/* Receieves input variables from user */
void get_variables(float *heat_transfer, float *thermal_conductivity,
  float *area, float *temp_one_side, float *temp_other_side, 
  float *conductor_thickness)
{
  char unknown_char; /* Char variable to scan question mark into */

  printf("Respond to the prompts, enter ? for unknown:\n");
  printf("Rate of heat transfer (watts) >> ");

  /* scans input and puts -1 in variable if a char (?) is received */
  if( !scanf("%f", heat_transfer))
  {
    *heat_transfer = -1;
    unknown_char = getchar(); /* Clears newline from buffer */
  }
  printf("Coefficient of thermal conductivity (W/m-K) >> ");
  if( !scanf("%f", thermal_conductivity))
  {
    *thermal_conductivity = -1;
    unknown_char = getchar(); /* Clears newline from buffer */
  }
  printf("Cross-sectional area of conductor: (W^2) >> ");
  if( !scanf("%f", area))
  {
    *area = -1;
    unknown_char = getchar(); /* Clears newline from buffer */
  }
  printf("Temperature on one side (K) >> ");
  if( !scanf("%f", temp_one_side))
  {
    *temp_one_side = -1;
    unknown_char = getchar(); /* Clears newline from buffer */

  }
  printf("Temperature on other side (K) >> ");
  if( !scanf("%f", temp_other_side))
  {
    *temp_other_side = -1;
    unknown_char = getchar(); /* Clears newline from buffer */

  }
  printf("Thickness of conductor (m) >> ");
  if( !scanf("%f", conductor_thickness))
  {
    *conductor_thickness = -1;
    unknown_char = getchar();

  }
}

/* Finds heat transfer and prints it */
float
calc_h(float thermal_conductivity, float area, float temp_one_side,
  float temp_other_side, float conductor_thickness)
{
  float heat_transfer = (thermal_conductivity * area * 
    (temp_one_side - temp_other_side)) / conductor_thickness;
  printf("Rate of head transfer is %.4f00 watts.\n", heat_transfer);
  return heat_transfer;
}

/* Finds coefficient of thermal conductivity and prints it */
float
calc_k(float heat_transfer, float area, float temp_one_side,
  float temp_other_side, float conductor_thickness)
{
  float thermal_conductivity = (heat_transfer * conductor_thickness) / 
    (area * (temp_one_side - temp_other_side));
  printf("Coefficient of thermal conductivity is %f W/m-K.\n",
    thermal_conductivity);
  return thermal_conductivity;
}

/* Finds cross-sectional area and prints it */
float
calc_a(float heat_transfer, float thermal_conductivity, float temp_one_side,
  float temp_other_side, float conductor_thickness)
{
  float area = (heat_transfer * conductor_thickness) / 
    (thermal_conductivity * (temp_one_side - temp_other_side));
  printf("Area of Conductor is %f m^2.\n", area);
  return area;
}

/* Finds temperature of one side and prints it */
float
calc_t1(float heat_transfer, float thermal_conductivity, float area,
  float temp_other_side, float conductor_thickness)
{
  float temp_one_side = ((heat_transfer * conductor_thickness) /
    (thermal_conductivity * area)) + temp_other_side;
  printf("Temperature on one side is  %.0f K.\n", temp_one_side);
  return temp_one_side;
}

/* Finds temperature of other side and prints it */
float
calc_t2(float heat_transfer, float thermal_conductivity, float area,
  float temp_one_side, float conductor_thickness)
{
  float temp_other_side = -1 * (((heat_transfer * conductor_thickness) /
    (thermal_conductivity * area)) - temp_one_side);
  printf("Temperature on other side is  %.0f K.\n", temp_other_side);
  return temp_other_side;

}

/* Finds thickness of the conductor and prints it */
float
calc_c(float heat_transfer, float thermal_conductivity, float area, 
  float temp_one_side, float temp_other_side)
{
  float conductor_thickness = (thermal_conductivity * area * 
    (temp_one_side - temp_other_side)) / heat_transfer;
  printf("Thickness %.4f m.\n", conductor_thickness);
  return conductor_thickness;
}

/* Displays all variables after calculating missing one */
void
display_variables(float heat_transfer, float thermal_conductivity, float area, 
  float temp_one_side, float temp_other_side, float conductor_thickness)
{
  printf("H = %.1f W               T2 = %.0f K\n", heat_transfer,
    temp_one_side);
  printf("k = %.4f W/m-K               T1 = %.0f K\n", thermal_conductivity, 
    temp_other_side);
  printf("A = %.3f m^2               X = %.4f K\n", area, conductor_thickness);
}