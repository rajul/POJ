#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int i, t, n, res;

	scanf("%d", &t);

	for(i=0; i<t; i++)
	{
		scanf("%d", &n);

		res = (int) sqrt(n);

		printf("%d\n", res);
	}

	return 0;
}