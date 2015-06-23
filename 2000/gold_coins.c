#include <stdio.h>
#include <math.h>

int sum_till_n(int n)
{
  return ((n * (n+1)) / 2);
}

int sum_squares_till_n(int n)
{
  return ((n * (n+1) * (2*n + 1)) / 6);
}

int n_for_a_sum(int s)
{
  int n;
  n = (int)((-1.0 + sqrt(8*s + 1)) / 2);
  return n;
}


int main(int argc, char *argv[])
{
  int i, n, total_coins;

  scanf("%d", &n);

  while(n != 0)
  {
    int x = n_for_a_sum(n);
    int s = sum_squares_till_n(x);
    int s_2 = sum_till_n(x);

    total_coins = s + (n - s_2) * (x + 1);

    printf("%d %d\n", n, total_coins);

    scanf("%d", &n);
  }

  return 0;
}
