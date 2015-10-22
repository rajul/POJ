#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n, count = 0;
	
	while(1)
	{
		scanf("%d", &n);

		if (n == 0)
			break;
		
		count++;

		printf("%d. ", count);

		if(n%2)
			printf("odd ");
		else
			printf("even ");

		printf("%d\n", n/2);
	}

	return 0;
}