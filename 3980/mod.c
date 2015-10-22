#include <stdio.h>

int modulo(int n, int m)
{
	int t = n / m;

	return (n - t*m);
}

int main(int argc, char *argv[])
{
	int n, m;

	while(scanf("%d %d\n", &n, &m) != EOF)
	{
		int t = n / m;

		printf("%d\n", modulo(n, m));
	}

	return 0;
}