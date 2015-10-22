#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int t, x, y;
	int i;

	scanf("%d\n", &t);

	for(i=0; i<t; i++)
	{
		scanf("%d %d\n", &x, &y);

		if(x < y)
			printf("NO BRAINS\n");
		else
			printf("MMM BRAINS\n");
	}

	return 0;
}