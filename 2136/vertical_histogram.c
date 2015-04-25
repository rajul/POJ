#include <stdio.h>
#include <string.h>

typedef struct {
  char alphabet;
  int num;
} HistElement;

void update_histogram(HistElement[], char[]);
int find_max_occurence(HistElement[]);
void print_vertical_hist(HistElement[], int);

int main()
{
  int i;
  char line[73];
  int max_occurence;
  HistElement vertical_hist[27]; 

  for(i=0; i<26; i++)
  {
    vertical_hist[i].alphabet = (char)(i+65);
    vertical_hist[i].num = 0;
  }

  for(i=0; i<4; i++)
  {
    fgets(line, 75, stdin);
    update_histogram(vertical_hist, line);
  }
  
  max_occurence = find_max_occurence(vertical_hist);
  
  print_vertical_hist(vertical_hist, max_occurence);

  return 0;
}

void print_vertical_hist(HistElement hist[], int max)
{
  int i, j;

  for(i=0; i<max; i++)
  {
    for(j=0; j < 26; j++)
    {
      if((max-i) > hist[j].num)
        printf(" ");
      else
        printf("*");

      if(j != 25)
        printf(" ");
    }
    printf("\n");
  }

  for(i=0; i<26; i++)
  {
    printf("%c", hist[i].alphabet);
    if(j != 25)
      printf(" ");
  }
  printf("\n");
}

int find_max_occurence(HistElement vert_hist[])
{
  int i, max = vert_hist[0].num;

  for(i=1; i<26; i++)
  {
    if(max < vert_hist[i].num)
    {
     max = vert_hist[i].num;
    }
  }
  
  return max; 
}

void update_histogram(HistElement vert_hist[], char line[])
{
  int i;
  int length = strlen(line);

  for(i=0; i<length; i++)
  {
  	if(line[i] >= 'A' && line[i] <= 'Z')
  	{
  		int t = (int)line[i] - 65;
  		vert_hist[t].num++;
  	}
  }
}
