#include <stdio.h>

typedef struct
{
  int num_of_inv;
  char sequence[51];
} DNASeq;

int get_num_inversions(char sequence[], int length)
{
  int i, j;
  int inversions = 0;

  for(i=0; i<length; i++)
  {
    for(j=(i+1); j< length; j++)
    {
      if(sequence[i] > sequence[j])
      {
        inversions++;
      }
    }
  }

  return inversions;
}

void sort_sequences(DNASeq seq[], int length)
{
  int i, j;

  for(i=0; i<length; i++)
  {
    DNASeq min = seq[i];
    int minpos = i;

    for(j=(i+1); j<length; j++)
    {
      if(min.num_of_inv > seq[j].num_of_inv)
      {
        min = seq[j];
        minpos = j;
      }
    }

    DNASeq t = seq[i];
    seq[i] = seq[minpos];
    seq[minpos] = t;
  }
}

int main(int argc, char *argv[])
{
  int n, m;
  int i;
  DNASeq seq[101];

  scanf("%d %d", &n, &m);

  for(i=0; i<m; i++)
  {
    scanf("%s", &seq[i].sequence[0]);

    seq[i].num_of_inv = get_num_inversions(seq[i].sequence, n);
  }

  sort_sequences(seq, m);
  
  for(i=0; i<m; i++)
  {
    printf("%s\n", seq[i].sequence);
  }

  return 0;
}
