#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double get_series_term(long n)
{
	double root;

	root = (-1 + sqrt(1+4*2*n)) / 2;
	
	return root;
}

double get_digit_at_nth_pos(long n)
{
	double root = get_series_term(n);

	return root;
}

int main(int argc, char *argv[])
{
	int t;
	long n;
	int i;
	double r;

	scanf("%d\n", &t);

	for(i=0; i<t; i++)
	{
		scanf("%ld\n", &n);
		printf("n: %ld\n", n);

		r = get_digit_at_nth_pos(n);

		printf("r: %lf\n", r);

		printf("\n");
	}

	return 0;
}