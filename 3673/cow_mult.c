#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int a, b;
	int l1=0, l2=0;
	int num1[100];
	int num2[100];
	int sum = 0, i, j;

	scanf("%d %d", &a, &b);

	while (a != 0)
	{
		num1[l1] = (a%10);
		a = a / 10;
		l1++;
	}


	while (b != 0)
	{
		num2[l2] = (b%10);
		b = b / 10;
		l2++;
	}

	for(i=0; i<l1; i++)
	{
		for(j=0; j<l2; j++)
		{
			sum = sum + num1[i] * num2[j];
		}
	}

	printf("%d\n", sum);

	return 0;
}