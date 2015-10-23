#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int N, dining_pref, i, t, min;
	
	int count_ones[30005];
	int count_twos[30005];
	
	int total_count_ones = 0;
	int total_count_twos = 0;

	scanf("%d\n", &N);

	for(i-0; i<N; i++)
	{
		scanf("%d\n", &dining_pref);

		if(dining_pref == 1)
		{
			total_count_ones++;
		}
		else
		{
			total_count_twos++;
		}

		count_ones[i] = total_count_ones;
		count_twos[i] = total_count_twos;
	}

	min = total_count_twos;

	for(i=0; i<N; i++)
	{
		t = count_twos[i] + (total_count_ones - count_ones[i]);

		if (t < min)
			min = t;
	}

	if (total_count_ones < min)
		min = total_count_ones;

	printf("%d\n", min);

	return 0;
}