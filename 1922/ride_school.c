#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int i;
  int n;
  int v, t;
  float temp;
  float min;
  int time_taken;

  while(1)
  {
    scanf("%d", &n);

    if(n == 0)
      break;

    min = 4.5 * 3600;
    
    for(i=0; i<n; i++)
    {
      scanf("%d %d", &v, &t);

      if(t < 0)
        continue;

      temp = (4.5/v) * 3600 + t;

      if(temp < min)
      {
        min = temp;
      }
    }

    // if((min - (int)min) > 0)
    // {
    //   time_taken = (int)min + 1;
    // else
    //   time_taken = (int)min

    time_taken = ceil(min);

    printf("%d\n", time_taken);
    // printf("%f\n", min);
  }

  return 0;
}


