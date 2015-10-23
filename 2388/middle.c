#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[])
{
	int N, i;
	int milk[10005];

	scanf("%d\n", &N);

	for(i=0; i<N; i++)
		scanf("%d\n", &milk[i]);

	qsort(milk, N, sizeof(int), cmpfunc);
	
	printf("%d\n", milk[N/2]);

	return 0;
}