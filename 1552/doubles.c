#include <stdio.h>
#include <stdlib.h>

int linear_search(int nums[], int key, int length)
{
	int i;

	for(i=0; i<length; i++)
	{
		if(nums[i] == key)
			return 1;
	}

	return 0;
}


int main(int argc, char *argv[])
{
	int t, count_numbers, i, count_doubles;
	int numbers[20];

	while(1)
	{
		count_numbers = 0;

		while(1)
		{
			scanf("%d", &t);

			if(t == 0 || t == -1)
				break;

			numbers[count_numbers] = t;
			count_numbers++;
		}

		if(t == -1)
			break;

		count_doubles = 0;

		for(i=0; i<count_numbers; i++)
		{
			t = 2 * numbers[i];

			if(linear_search(numbers, t, count_numbers) == 1)
				count_doubles++;
		}

		printf("%d\n", count_doubles);
	}

	return 0;
}