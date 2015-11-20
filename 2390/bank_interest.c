#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int r, m, y;
	double amt;
	int amt_int;

	scanf("%d %d %d\n", &r, &m, &y);

	amt = m * pow((1 + r/100.0), y);

	amt_int = (int)amt;

	printf("%d\n", amt_int);

	return 0;
}