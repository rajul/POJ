/*
	This one has a lot of prints put during the
	step-wise developement and debugging of program.
	Submitted the one without comments, present in 
	the same directory 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alphabets[26];
long permutation_sizes[10];
long permutation_ranges_limits[10];

void fill_alphabets()
{
	int i;

	for(i=0; i<26; i++)
	{
		alphabets[i] = i + 65;
	}
}

long get_permutation_size(int n)
{
	int i;
	long prod = 1;

	for(i=0; i<n; i++)
	{
		prod = prod * 26;
	}

	return prod;
}

void fill_permutation_sizes()
{
	int i;

	for(i=0; i<6; i++)
	{
		permutation_sizes[i] = get_permutation_size(i+1);
	}
}

void fill_permutation_range_limits()
{
	int i;

	permutation_ranges_limits[0] = permutation_sizes[0];

	for(i=1; i<6; i++)
	{
		permutation_ranges_limits[i] = permutation_sizes[i] + permutation_ranges_limits[i-1];
	}
}

long get_row(char str[])
{
	int i=0;
	int start, end;
	long sum = 0;
	char ch;
	
	while(1)
	{
		ch = str[i];

		if(ch == 'R')
		{
			start = i + 1;
		}

		if(ch == 'C')
		{
			end = i;
			break;
		}

		i++;
	}

	for(i=start; i<end; i++)
	{
		sum = 10*sum + (str[i] - '0');
	}

	return sum;
}


long get_col(char str[])
{
	int i=0;
	int start, end;
	long sum = 0;
	char ch;
	
	while(1)
	{
		ch = str[i];

		if(ch == 'C')
		{
			start = i+1;
			break;
		}

		i++;
	}

	end = strlen(str);

	for(i=start; i<end; i++)
	{
		sum = 10*sum + (str[i] - '0');
	}

	return sum;
}

int get_num_chars_col_name(int col)
{
	int i;

	for(i=0; i<6; i++)
	{
		if (col <= permutation_ranges_limits[i])
			return (i+1);
	}

	return 0;
}


void get_nth_permutation(int num_chars, int permutation_number, char perm[])
{
	int i;
	int permutation_index = permutation_number - 1;
	long total_permutations = permutation_sizes[num_chars - 1];
	int q, r;

	printf("Total permutations: %ld\n", total_permutations);

	for(i=0; i<num_chars; i++)
	{
		r = permutation_index % 26;
		perm[i] = alphabets[r];

		printf("char: %c\n", perm[i]);
		
		permutation_index = permutation_index / 26;
	}

	perm[i] = '\0';
}

void get_col_name(int col, char final_col_name[])
{
	int num_chars = get_num_chars_col_name(col);
	int permutation_number;

	if (num_chars == 1)
		permutation_number = col;
	else
		permutation_number = col - permutation_ranges_limits[num_chars - 2];

	printf("Num of chars in column name: %d\n", num_chars);
	printf("Permutation number: %d\n", permutation_number);

	get_nth_permutation(num_chars, permutation_number, final_col_name);
}


int main(int argc, char *argv[])
{
	int i, l;
	char input[50];
	char col_name[30];
	long row, col;

	fill_alphabets();
	fill_permutation_sizes();
	fill_permutation_range_limits();


	for(i=0; i<26; i++)
		printf("%c ", alphabets[i]);

	printf("\n");

	for(i=0; i<6; i++)
		printf("%ld\n", permutation_sizes[i]);

	printf("\n");

	for(i=0; i<6; i++)
		printf("%ld\n", permutation_ranges_limits[i]);

	while(1)
	{
		scanf("%s", input);

		if(strcmp(input, "R0C0") == 0)
			break;

		printf("Input String: %s\n", input);

		row = get_row(input);
		col = get_col(input);

		get_col_name(col, col_name);

		printf("Row: %ld\n", row);
		printf("Col: %ld\n", col);

		int l = strlen(col_name);

		for(i=(l-1); i>=0; i--)
			printf("%c", col_name[i]);
		
		printf("%ld\n", row);
	}

	return 0;
}