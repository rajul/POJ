/*
	Not Accepted: slow
*/

#include <stdio.h>
#include <stdlib.h>

long recaman_terms[500005];

int is_term_already_present(int k, long term)
{
	int i;

	for(i=0; i<k; i++)
	{
		if(recaman_terms[i] == term)
			return 1;
	}

	return 0;
}

long get_recaman_term(int k)
{
	// printf("Call in get func: %d\n", k);
	long term = 0;

	if(k == 0)
	{
		// printf("Returns 0\n");
		return 0;
	}
		
	if(recaman_terms[k] != -1)
	{
		// printf("Using pre-calculated\n");
		term = recaman_terms[k];
	}
	else
	{
		term = get_recaman_term(k-1) - k;

		if (term <= 0 || is_term_already_present(k, term))
			term = get_recaman_term(k-1) + k;

		recaman_terms[k] = term;
	}

	return term;
}


int main(int argc, char *argv[])
{
	int i;

	for(i=0; i<500002; i++)
		recaman_terms[i] = -1;
	
	// printf("%ld\n", recaman_terms[7]);


	get_recaman_term(50000);

	printf("%ld\n", recaman_terms[50000]);

	return 0;
}
