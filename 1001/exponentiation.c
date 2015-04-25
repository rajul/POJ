#include <stdio.h>
#include <string.h>

int get_decimal_position(char[]);
int get_numeric_rep(char[]);
void strip_trailing_zeros(char[]);
void multiply(int[], int);

int result[151];
int len_result;

int main(int argc, char *argv[])
{
  int i;
  int n;
  char r[7];
  int decimal_pos, decimal_pos_in_res;
  int numeric_rep;

  while(scanf("%s %d", r, &n) == 2)
  {
    result[0] = 1;
    len_result = 1;

    strip_trailing_zeros(r);
    decimal_pos = get_decimal_position(r);
    numeric_rep = get_numeric_rep(r);

    // if(numeric_rep == 0)
    // {
    //    printf("%d\n", numeric_rep);
    //    continue;
    // }

    for(i=0; i < n; i++)
    {
      multiply(result, numeric_rep);
    }

    decimal_pos_in_res = decimal_pos * n;

    // values less than 1
    if (decimal_pos_in_res >= len_result)
    {
      printf(".");

      for(i=0; i < (decimal_pos_in_res - len_result); i++)
        printf("0");

      for(i=(len_result-1); i>=0; i--)
        printf("%d", result[i]);

      printf("\n");
    }
    else
    {
      for(i=(len_result - 1); i >= 0; i--)
      {
        printf("%d", result[i]);

        if(i == decimal_pos_in_res && decimal_pos_in_res != 0)
        	printf(".");
      }

      printf("\n");
    }
  }

  return 0;
}

void multiply(int num[], int n)
{
  int i;
  int carry = 0;

  for(i=0; i < len_result; i++)
  {
    int t = num[i] * n + carry;
    num[i] = t % 10;
    carry = t / 10;
  }

  while (carry != 0)
  {
    num[i++] = carry % 10;
    carry = carry / 10;
  }

  len_result = i;
}

int get_numeric_rep(char num[])
{
  int i;
  int n = 0;
  int l = strlen(num);

  for(i=0; i<l; i++)
  {
    if(num[i] >= '0' && num[i] <= '9')
      n = n * 10 + (num[i] - '0');
  }

  return n;
}

void strip_trailing_zeros(char num[])
{
  int l = strlen(num);
  int i;

  for(i=(l-1); i>0; i--)
  {
    if(num[i] != '0')
    {
      num[i+1] = '\0';
      break;
    }
  }
}


// Returns the power of 10 after decimal point....
// That is power of 10 in denominator if decimal removed
int get_decimal_position(char num[])
{
  int i;
  int pos = -1;
  int l = strlen(num);

  for(i=0; i<l; i++)
  {
    if(num[i] == '.')
    {
      pos = i;
      break;
    }
  }

  if(pos != -1)
    return (l - pos - 1);
  else
    return 0;
}
