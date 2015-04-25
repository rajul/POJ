#include <stdio.h>

int main()
{
  int i;
  float sum=0.0;

  for(i=0; i<12; i++)
  {
    float a;

    scanf("%f", &a);
    sum = sum + a;
  }

  printf("$%.2f\n", (sum/12));
  
  return 0;
}

