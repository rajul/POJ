#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_inversion_count(char seq[], int l)
{
  int inversions=0;
  int i, j;

  for(i=0; i<l; i++)
  {
    for(j=i+1; j<l; j++)
    {
      if(seq[i] > seq[j])
      {
        inversions++;
      }
    }
  }

  return inversions;
}

int main(int argc, char *argv[])
{
  int i, j;
  int n, m, t;
  scanf("%d %d", &n, &m);
  
  int inversion_count[100];
  int inversion_index[100];
  char seq[101][51];
  // char seq_copy[101][51];

  for(i=0; i<m; i++)
  {
    scanf("%s", &seq[i][0]);
    strcpy(seq_copy[i], seq[i]);
  }

  for(i=0; i<m; i++)
  {
    inversion_count[i] = get_inversion_count(seq[i], n);
    inversion_index[i] = i;
  }

  int min, minpos;

  for(i=0; i<m; i++)
  {
    min = inversion_count[i];
    minpos = i;

    for(j=i+1; j<m; j++)
    {
      if(min > inversion_count[j])
      {
        min = inversion_count[j];
        minpos = j;
      }
      
      if(min == inversion_count[j])
      {
        if(inversion_index[minpos] > inversion_index[j])
        {
          min = inversion_count[j];
          minpos = j;
        }
      }
      
    }
    
    int t = inversion_count[i];
    inversion_count[i] = inversion_count[minpos];
    inversion_count[minpos] = t;
    
    t = inversion_index[i];
    inversion_index[i] = inversion_index[minpos];
    inversion_index[minpos] = t;
  }

  for(i=0; i<m; i++)
  {
    printf("%d %d\n", inversion_count[i], inversion_index[i]);    
    // t = inversion_index[i];
    // printf("%s\n", seq_copy[t]);    
  }

  return 0;
}

