#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n;
	int s[20], t[20], d[20];
	int i;

	while(1)
	{
		scanf("%d", &n);

		if(n == -1)
			break;

		int dist = 0;

		for(i=0; i<n; i++)
		{
			scanf("%d %d\n", &s[i], &t[i]);
		}

		// Map t's
		d[0] = t[0];
		for(i=1; i<n; i++)
		{
			d[i] = t[i] - t[i-1];
		}

		for(i=0; i<n; i++)
		{
			dist = dist + s[i] * d[i];
		}

		printf("%d miles\n", dist);
	}

	return 0;
}