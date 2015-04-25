#include <stdio.h>

int get_reversed(int);

int main(int argc, char *argv[])
{
  int i;
  int n;
  int x, y, result;
  int rev_x, rev_y, rev_result;

  scanf("%d", &n);

  for(i=0; i<n; i++)
  {
    scanf("%d %d", &x, &y);
    
    rev_x = get_reversed(x);
    rev_y = get_reversed(y);

    result = rev_x + rev_y;
    rev_result = get_reversed(result);

    printf("%d\n", rev_result);
  }

  return 0;
}

int get_reversed(int x)
{
  int t;
  int result = 0;

  while(x != 0)
  {
    t = x % 10;
    result = result * 10 + t;
    x = x/10;
  }

  return result;
}

