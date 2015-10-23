#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int M, T, U, F, D;
	char terrain[100005];
	int i;
	int total_time = 0;
	int total_distance = 0;

	scanf("%d %d %d %d %d\n", &M, &T, &U, &F, &D);

	int flat_time = 2 * F;
	int up_down_time = U + D;

	for(i=0; i<T; i++)
	{
		scanf("%c\n", &terrain[i]);
	}

	for(i=0; i<T; i++)
	{
		if(terrain[i] == 'f')
			total_time = total_time + flat_time;
		else
			total_time = total_time + up_down_time;

		if(total_time > M)
			break;

		total_distance++;
	}

	printf("%d\n", total_distance);

	return 0;
}