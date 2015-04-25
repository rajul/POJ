#include <stdio.h>

int main(int argc, char *argv[])
{
  int i, count=1;
  float sums[1000];
  float c, sum=0.0;

  while(sum <= 5.2)
  {
    count = count + 1;
    sum = sum + (1.0 / count);
    sums[count - 2] = sum;
  }

  scanf("%f", &c);
  
  while(c != 0.0)
  {
    for(i=0; i<count; i++)
    {
      if(sums[i] >= c)
      {
        printf("%d card(s)\n", i + 1);
        break;
      }
    }
    
    scanf("%f", &c);
  }

  return 0;
}
