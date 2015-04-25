#include <stdio.h>

#define sqr(x) ((x) * (x))

typedef struct 
{
  int x;
  int y;
} Point;

int check_within_grid(Point p, int max)
{
  if (p.x >= 0 && p.x < max && p.y >= 0 && p.y < max)
    return 1;
  
  return 0;
}

int check_xy_even(Point p)
{
  if((p.x % 2) || (p.y %2))
    return 0;

  return 1;
}

int main(int argc, char *argv[])
{
  int i, j;
  int n;
  char map[110][110];
  Point cow_pos[10010];
  

  while(scanf("%d", &n) == 1)
  {
    for(i=0; i<n; i++)
    {
      scanf("%s", map[i]);
    }
    
    int count = 0;

    for(i=0; i<n; i++)
    {
      for(j=0; j<n; j++)
      {
        if(map[i][j] == 'J')
        {
          cow_pos[count].x = i;
          cow_pos[count].y = j;

          count++;
        }
      }
    }
    
    int area, res = 0;
    Point p1, p2, p3, p4;  
    
    for(i=0; i<count; i++)
    {
      p1 = cow_pos[i];

      for(j=i+1; j<count; j++)
      {
        p2 = cow_pos[j];

        area = (sqr(p1.x - p2.x) + sqr(p1.y - p2.y))/2;

        if(area <= res)
          continue;

        p3.x = (p1.x + p2.x + p1.y - p2.y);
        p3.y = (p1.y + p2.y + p2.x - p1.x);
        
        p4.x = (p1.x + p2.x + p2.y - p1.y);
        p4.y = (p1.y + p2.y + p1.x - p2.x);
        
        if(check_xy_even(p3) && check_xy_even(p4))
        {
          p3.x /= 2;
          p3.y /= 2;
          
          p4.x /= 2;
          p4.y /= 2;
        }
        else
        {
          continue;
        }

        if(!check_within_grid(p3, n) || !check_within_grid(p4, n))
          continue;

        char t = map[p3.x][p3.y];
        char u = map[p4.x][p4.y];

        if((t == 'J' || u == 'J') && (t != 'B' && u != 'B'))
        {
          res = area;
        }
      }
    }

    printf("%d\n", res);
  }

  
  return 0;
}
