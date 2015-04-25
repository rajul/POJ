#include <stdio.h>
#include <math.h>

#define PI acos(-1)

int main(int argc, char *argv[])
{
  int t, n, i;
  float R, r, temp;

  scanf("%d", &t);

  for(i=0; i<t; i++)
  {
    printf("Scenario #%d:\n", i+1);

    scanf("%f %d", &R, &n);

    temp = sin(PI/n);

    r = R * ((temp)/(1+temp));

    printf("%.3f\n", r);
    printf("\n");
  }

  return 0;
}