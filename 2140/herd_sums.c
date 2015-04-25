#include <stdio.h>

int main(int argc, char *argv[])
{
  int i, j, n, count=0;

  scanf("%d", &n);

  for(i=n; i>0; i--)
  {
    int sum = 0;
    for(j=i; j>0; j--)
    {
      sum = sum + j;

      if(sum == n)
        count++;

      if(sum >= n)
        break;
    }
  }

  printf("%d\n", count);

  return 0;
}
