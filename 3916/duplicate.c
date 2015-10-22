#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n, i;
	int nums[30];

	while(1)
	{
		scanf("%d", &n);

		if (n == 0)
			break;

		for(i=0; i<n; i++)
			scanf("%d", &nums[i]);

		printf("%d ", nums[0]);

		for(i=1; i<n; i++)
		{
			if(nums[i] != nums[i-1])
				printf("%d ", nums[i]);
		}
		printf("$\n");
	}

	return 0;
}