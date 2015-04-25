#include <stdio.h>
#include <string.h>

int main()
{
  int i, j;
  char line[73];
  int max_occurence;
  int occurences[27]; 

  for(i=0; i<26; i++)
    occurences[i] = 0;

  for(i=0; i<4; i++)
  {
    fgets(line, 75, stdin);
    
    int length = strlen(line);
    for(j=0; j<length; j++)
    {
      if(line[j] <= 'Z' && line[j] >= 'A')
      {
        int t = (int)line[j] - 'A';
        occurences[t]++;
      }
    }
  }

  max_occurence = occurences[0];
  for(i=0; i<26; i++)
  {
    if(max_occurence < occurences[i])
      max_occurence = occurences[i];
  }

  for(i=0; i<max_occurence; i++)
  {
    for(j=0; j<26; j++)
    {
      if((max_occurence - i) > occurences[j])
        putchar(' ');
      else
        putchar('*');

      if(j != 25)
        putchar(' ');
    }

    putchar('\n');
  } 
  
  for(i=0; i<26; i++)
  {
    printf("%c", (char)(i + 'A'));
    
    if(j != 25)
      putchar(' ');
  }
  
  putchar('\n');

  return 0;
}

