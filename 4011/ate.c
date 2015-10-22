#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n, x;

	scanf("%d", &n);

	if(n > 198)
		x = 0;
	else
		x = 198 - n + 1; // 99 - (n - 99) + 1

	printf("%d\n", x);

	return 0;
}