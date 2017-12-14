#include <stdio.h>
#include <stdlib.h>

long nums[500005];
long temp[500005];

int merge_and_count_split_inv(int left_start, int left_end, int right_start, int right_end)
{
	int l = left_start;
	int r = right_start;
	int total_split_inv = 0;
	int num_elems_left = left_end - left_start;
	int num_elems_right = right_end - right_start;
	int i, j;

	for(i=left_start; i<right_end ; i++)
	{
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

		if(l == left_end || r == right_end)
			break;
	}

	if(l == left_end)
	{
		for(j=(i+1); j < right_end && r < right_end ; j++)
		{
			temp[j] = nums[r];
			r++;
		}
	}

	if(r == right_end)
	{
		for(j=(i+1); j < right_end && l < left_end ; j++)
		{
			temp[j] = nums[l];
			l++;
		}
	}

	for(i=left_start; i<right_end ; i++)
	{
		nums[i] = temp[i];
	}

	return total_split_inv;
}

int sort_and_count_inversions(int start, int end)
{
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

		printf("%d\n", inv);
	}
	
	return 0;
}