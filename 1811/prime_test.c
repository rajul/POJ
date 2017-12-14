#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long run_prime_test(long long n)
{
	if(n == 2 || n == 3)
		return 0;

	if(n % 2 == 0)
		return 2;

	if(n % 3 == 0)
		return 3;

	long t = sqrt(n);
	long i;

	for(i=6; i < t; i=(i+6))
	{
		if(n % (i-1) == 0 && n != (i-1))
			return i-1;

		if(n % (i+1) == 0 && n != (i+1))
			return i+1;
	}

	return 0;
}


int main(int argc, char *argv[])
{
	int T, i;
	long res;
	long long N;

	scanf("%d\n", &T);

	for(i=0; i<T; i++)
	{
		scanf("%lld\n", &N);

		res = run_prime_test(N);

		if (res == 0)
		{
			printf("Prime\n");
		}
		else
		{
			printf("%ld\n", res);
		}
	}

	return 0;
}