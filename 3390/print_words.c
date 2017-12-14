#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int T, M, N;
	int i, j, penalty, temp_total;
	int word_lengths[10005];

	scanf("%d\n", &T);

	for(i=0; i<T; i++)
	{
		temp_total = 0;
		penalty = 0;

		scanf("%d\n", &M);
		scanf("%d\n", &N);

		for(j=0; j<N; j++)
		{
			scanf("%d\n", &word_lengths[j]);
			printf("%d: %d\n", j, word_lengths[j]);
		}


		for(j=0; j<N; j++)
		{
			if(temp_total != 0)
				temp_total = temp_total + 1;

			temp_total = temp_total + word_lengths[j];

			if(temp_total > M)
			{
				temp_total = temp_total - word_lengths[j] - 1;
				printf("%d: inner temp_total = %d\n", j, temp_total);

				penalty = penalty + (M - temp_total) * (M - temp_total);
				temp_total = word_lengths[j];
			}

			printf("%d: temp_total = %d\n", j, temp_total);
			printf("%d: penalty = %d\n", j, penalty);

		}

		penalty = penalty + (M - temp_total) * (M - temp_total);

		printf("%d\n", penalty);
		printf("\n");

	}

	return 0;
}