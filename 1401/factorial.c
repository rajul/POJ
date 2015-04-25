#include <stdio.h>
#include <math.h>

int get_log_base_5(long);

int main()
{
  long n, res, temp;
  int t, i, j;
  
  scanf("%d", &t);

  for(i=0; i<t; i++)
  {
    scanf("%ld", &n);

    temp = 1;
    res = 0;

    for(j=0; temp < n; j++)
    {
      temp = temp * 5;      
      res = res + (n/temp);
    }

    printf("%ld\n", res);
  }

  return 0;
}
