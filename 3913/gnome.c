#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int t, i;
	int gnomes[35];
	int flag1, flag2;
	int x, y, z;

	scanf("%d\n", &t);

	printf("Gnomes:\n");
	for(i=0; i<t; i++)
	{
		scanf("%d %d %d\n", &x, &y, &z);

		if (x < y)
			flag1 = -1;
		else
			flag1 = 1;


		if (y < z)
			flag2 = -1;
		else
			flag2 = 1;

		if(flag1 == flag2)
			printf("Ordered\n");
		else
			printf("Unordered\n");
	}

	return 0;
}