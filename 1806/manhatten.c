#include <stdio.h>

int main(int argc, char *argv[])
{
  int i;
  int n, u;
  int x, y, z, d;

  scanf("%d", &n);

  for(i=0; i<n; i++)
  {
    scanf("%d", &u);

    printf("Scenario #%d:\n", i+1);

    for(x=(-u); x <= u; x++)
    {
      printf("slice #%d:\n", (x + u + 1));
      for(y=(-u); y <= u; y++)
      {
        for(z=(-u); z <= u; z++)
        {
          d = abs(x) + abs(y) + abs(z);

          if(d > u)
            printf(".");
          else
            printf("%d", d);
        }
        printf("\n");
      }
    }

    printf("\n");
  }

  return 0;
}
