#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char s[100005], t[100005];
	int len_s, len_t;
	int i, j;

	while(scanf("%s %s\n", s, t) != EOF)
	{
		len_s = strlen(s);
		len_t = strlen(t);

		i = 0;
		j = 0;

		while ((i < len_s) && (j < len_t))
		{
			if(t[j] == s[i])
				i++;

			j++;
		}

		if (i == len_s)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}