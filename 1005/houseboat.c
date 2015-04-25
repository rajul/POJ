#include <stdio.h>

#define PI 3.1415926

int main(void)
{
  int i;
  int n, year;
  double x, y, area;

  scanf("%d", &n);

  for(i=0; i<n; i++)
  {
    scanf("%lf %lf", &x, &y);

    area = (PI * (x*x + y*y)) / 2.0;

    year = (int)(area / 50.0) + 1;

    printf("Property %d: This property will begin eroding in year %d.\n", i+1, year);
  }

  printf("END OF OUTPUT.\n");

  return 0;
}