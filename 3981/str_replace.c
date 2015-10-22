#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char word[20];
	int count = 0;

	while(scanf("%s", word) != EOF)
	{
		if(strcmp(word, "you") == 0)
			printf("we");
		else
			printf("%s", word);

		char ch = getchar();
		printf("%c", ch);

		count++;
	}

	return 0;
}