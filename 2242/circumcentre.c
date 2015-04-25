// Circumcenter Method

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

Point get_circumcenter(Point p1, Point p2, Point p3)
{
  Point mid_1, mid_2;
  double temp;
  double slope1, slope2;
  Point center;

  if(p1.y == p2.y)
  {
    temp = p3.x;
    p3.x = p2.x;
    p2.x = temp;
  
    temp = p3.y;
    p3.y = p2.y;
    p2.y = temp;
  }
  
  if(p2.y == p3.y)
  {
    temp = p1.x;
    p1.x = p2.x;
    p2.x = temp;
  
    temp = p1.y;
    p1.y = p2.y;
    p2.y = temp;
  }

  mid_1.x = (p1.x + p2.x) / 2.0;
  mid_1.y = (p1.y + p2.y) / 2.0;

  mid_2.x = (p2.x + p3.x) / 2.0;
  mid_2.y = (p2.y + p3.y) / 2.0;

  slope1 = -(p1.x - p2.x) / (p1.y - p2.y); 
  slope2 = -(p2.x - p3.x) / (p2.y - p3.y);

  center.x = ((mid_2.y - mid_1.y) + (slope1 * mid_1.x - slope2 * mid_2.x)) / (slope1 - slope2);
  center.y = ((slope1 * slope2 * (mid_2.x - mid_1.x)) - (slope1 * mid_2.y - slope2 * mid_1.y))  / (slope2 - slope1);

  return center;
}


int main(int argc, char *argv[])
{
  Point p1, p2, p3, center;
  double r, c;

  while(
      scanf(
        "%lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y) != EOF
      )
  {
    center = get_circumcenter(p1, p2, p3);

    r = get_distance(center, p1);

    c = 2 * PI * r;

    printf("%.2f\n", c);
  }

  return 0;
}
