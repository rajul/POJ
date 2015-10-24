/*
	Using string to get the initial number.
	Using simple int gives and error.
	So the input integers can be arbitrarily large
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_sum_of_digits(int n)
{
	int sum = 0;

	while(n != 0)
	{
		sum = sum + n % 10;
		n = n / 10;
	}

	return sum;
}

int get_digital_root(int n)
{
	int root;

	while(1)
	{
		root = get_sum_of_digits(n);

		if(root < 10)
			break;
		else
			n = root;
	}

	return root;
}


int main(int argc, char *argv[])
{
	char input[1000];
	int n, l, i;

	while(1)
	{
		scanf("%s\n", input);

		if(strcmp(input, "0") == 0)
			break;

		l = strlen(input);
		n = 0;

		for(i=0; i<l; i++)
			n = n + input[i] - '0';

		printf("%d\n", get_digital_root(n));
	}

	return 0;
}