#include <stdio.h>
#include <stdlib.h>

long nums[500005];
long temp[500005];

int merge_and_count_split_inv(int left_start, int left_end, int right_start, int right_end)
{
	// printf("Left start, end: %d, %d\n", left_start, left_end);
	// printf("Right start, end: %d, %d\n", right_start, right_end);

	int l = left_start;
	int r = right_start;
	int total_split_inv = 0;
	int num_elems_left = left_end - left_start;
	int num_elems_right = right_end - right_start;
	int i, j;

	for(i=left_start; i<right_end ; i++)
	{
		// printf("\n");
		// printf("i: %d\n", i);
		// printf("Initial l, r: %d, %d\n", l, r);
		// printf("nums[l]: %ld\n", nums[l]);
		// printf("nums[r]: %ld\n", nums[r]);
		

		if(nums[l] <= nums[r])
		{
			temp[i] = nums[l];
			l++;
		}
		else
		{
			temp[i] = nums[r];
			r++;

			total_split_inv = total_split_inv + (left_end - l);
		}

		// printf("Final l, r: %d, %d\n", l, r);
		// printf("\n");

		if(l == left_end || r == right_end)
			break;
	}

	if(l == left_end)
	{
		for(j=(i+1); j < right_end && r < right_end ; j++)
		{
			// printf("j: %d\n", j);
			temp[j] = nums[r];
			r++;
		}
	}

	if(r == right_end)
	{
		for(j=(i+1); j < right_end && l < left_end ; j++)
		{
			// printf("j: %d\n", j);
			temp[j] = nums[l];
			l++;
		}
	}

	// printf("Temp: ");
	for(i=left_start; i<right_end ; i++)
	{
		// printf("%ld ", temp[i]);
		nums[i] = temp[i];
	}
	// printf("\n");

	return total_split_inv;
}

int sort_and_count_inversions(int start, int end)
{
	printf("Start, End: %d, %d\n", start, end);

	int mid = (start+end)/2;
	int left_inv, right_inv, split_inv;
	int num_of_elements = end - start;
	int num_inv;

	if(num_of_elements <= 1)
		return 0;

	left_inv = sort_and_count_inversions(start, mid);
	right_inv = sort_and_count_inversions(mid, end);
	split_inv = merge_and_count_split_inv(start, mid, mid, end);

	num_inv = left_inv + right_inv + split_inv;

	printf("Number of inversions: %d\n", num_inv);
	printf("\n");

	return num_inv;
}

int main(int argc, char *argv[])
{
	int n, i, inv;

	while(1)
	{
		scanf("%d\n", &n);

		if(n == 0)
			break;

		for(i=0; i<n ; i++)
		{
			scanf("%ld\n", &nums[i]);
		}

		inv = sort_and_count_inversions(0, n);

		for(i=0; i<n; i++)
			printf("%ld ", nums[i]);
		printf("\n");

		printf("%d\n", inv);

		// printf("\n");
		// printf("\n");
		// printf("\n");
	}

	return 0;
}