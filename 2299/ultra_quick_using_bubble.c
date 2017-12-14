// Time limit exceeded....need to look at the 
// more efficient num inversions method

#include <stdio.h>
#include <stdlib.h>

int bubble_sort(int nums_to_sort[], int n)
{
	int i, j;
	int count = 0;

	for(i=0; i<n; i++)
	{
		for(j=0; j<(n-i-1); j++)
		{
			if(nums_to_sort[j] > nums_to_sort[j+1])
			{
				int t = nums_to_sort[j];
				nums_to_sort[j] = nums_to_sort[j+1];
				nums_to_sort[j+1] = t;

				count++;
			}
		}
	}

	return count;
}

int main(int argc, char *argv[])
{
	int n, i;
	int nums[500000];
	int count;

	while(1)
	{
		scanf("%d\n", &n);

		if (n == 0)
			break;

		for(i=0; i<n ; i++)
		{
			scanf("%d\n", &nums[i]);
		}

		count = bubble_sort(nums, n);

		printf("%d\n", count);
	}

	return 0;
}