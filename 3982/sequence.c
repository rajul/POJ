// Not working...need to use BigInt somehow

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	long long seq[105];
	int i;

	while(scanf("%lld %lld %lld", &seq[0], &seq[1], &seq[2]) != EOF)
	{
		for(i=3; i<100; i++)
		{
			seq[i] = seq[i-1] + seq[i-2] + seq[i-3];

			printf("%d: %lld\n", i, seq[i]);
		}

		printf("%lld\n", seq[99]);
	}

	return 0;
}