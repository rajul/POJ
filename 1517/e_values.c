#include <stdio.h>
#include <stdlib.h>

int factorial[15];

void fill_factorial()
{
	int i;

	factorial[0] = 1;

	for(i=1; i<10; i++)
	{
		factorial[i] = i * factorial[i-1];
	}
}

int main(int argc, char *argv[])
{
	double e;
	int i, j;

	fill_factorial();

	printf("n e\n");
	printf("- -----------\n");

	for(i=0; i<10; i++)
	{
		e = 0.0;

		for(j=0; j<=i; j++)
		{
			e = e + (1.0 / factorial[j]);
		}

		printf("%d %.10g\n", i, e);
	}


	return 0;
}