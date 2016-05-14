#include <stdio.h>

#define MAX 500000

long recaman[500005];
long term_flag[3500000];

void calculate_recaman_seq()
{
	int i;

	recaman[0] = 0;

	for(i=1; i <= 500000; i++)
	{
		recaman[i] = recaman[i-1] - i;

		if(recaman[i] <= 0 || term_flag[recaman[i]] == 1)
			recaman[i] = recaman[i-1] + i;

		term_flag[recaman[i]] = 1;
	}
}

int main(int argc, char *argv[])
{
	int i, n;

	calculate_recaman_seq();

	while(1)
	{
		scanf("%d\n", &n);

		if (n == -1)
			break;

		printf("%ld\n", recaman[n]);			
	}

	return 0;	
}
