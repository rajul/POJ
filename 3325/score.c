#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n, score;
	int min, max, sum, avg;
	int i;

	while(1)
	{
		scanf("%d", &n);

		if (n == 0)
			break;

		min = 1000000, max = -1, sum = 0; 

		for(i=0; i<n ; i++)
		{
			scanf("%d", &score);

			if (score > max)
				max = score;

			if (score < min)
				min = score;

			sum = sum + score;
		}

		sum = sum - min - max;

		avg = sum / (n-2);

		printf("%d\n", avg);
	}

	return 0;	
}