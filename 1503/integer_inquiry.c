#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numbers[105][105];
int count = 0;
char sum[105];

void add_to_numbers(char num_str[], int index)
{
	int l = strlen(num_str);
	int n = 105 - l;
	int i;

	for(i=0; i<n; i++)
	{
		numbers[index][i] = 0;
	}

	for(i=n; i<105; i++)
	{
		numbers[index][i] = num_str[i-n] - '0';
	}
}

void calculate_sum_of_numbers()
{
	int i, j, col_sum, carry = 0, t;

	for(i=104; i>=0; i--)
	{
		col_sum = carry;

		for(j=0; j<count; j++)
		{
			col_sum = col_sum + numbers[j][i];
		}

		t = col_sum % 10;
		carry = col_sum / 10;

		sum[i] = t + '0';
	}
}

void pretty_print_sum()
{
	int i, j;

	for(i=0; i<105; i++)
	{
		if(sum[i] != '0')
			break;
	}

	for(j=i; j<105; j++)
	{
		printf("%c", sum[j]);
	}

	if(i == 105)
		printf("0");

	printf("\n");
}

int main(int argc, char *argv[])
{
	char temp_num[105];

	while(1)
	{
		scanf("%s\n", temp_num);

		if(strcmp(temp_num, "0") == 0)
			break;

		add_to_numbers(temp_num, count);
		count++;
	}

	calculate_sum_of_numbers();

	pretty_print_sum();
	
	return 0;
}