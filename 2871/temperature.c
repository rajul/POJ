#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	float x, y;

	scanf("%f", &x);

	while(1)
	{
		scanf("%f", &y);

		if (y == 999)
			break;

		printf("%.2f\n", (y-x));

		x = y;
	}

	printf("End of Output\n");

	return 0;
}