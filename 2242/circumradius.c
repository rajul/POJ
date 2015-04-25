// Circumradius Method

#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

typedef struct {
  double x;
  double y;
} Point;

double get_distance(Point p1, Point p2)
{
  double d_to_2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
  return sqrt(d_to_2);
}

double get_circumradius(Point p1, Point p2, Point p3)
{
  double a, b, c, s, r;

  a = get_distance(p1, p2);
  b = get_distance(p2, p3);
  c = get_distance(p1, p3);

  s = (a + b + c) / 2.0;
  r = (a * b * c) / (4 * sqrt(s * (a + b - s) * (b + c - s) * (a + c - s)));

  return r;
}

int main(int argc, char *argv[])
{
  Point p1, p2, p3;
  double r, c;

  while(
      scanf(
        "%lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y) != EOF
      )
  {
    r = get_circumradius(p1, p2, p3);

    c = 2 * PI * r;

    printf("%.2f\n", c);
  }

  return 0;
}
