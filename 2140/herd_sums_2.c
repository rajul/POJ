#include <stdio.h>

int main(int argc, char *argv[])
{
  int i, j, n, count=0;

  scanf("%d", &n);

  for(i=n; i>0; i--)
  {
    int sum_twice = 0;
    for(j=i; j>=0; j--)
    {
      sum_twice = (i - j) * (i + j + 1);

      if(sum_twice == (2 * n))
        count++;

      if(sum_twice >= (2 * n))
        break;
    }
  }

  printf("%d\n", count);

  return 0;
}
