#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, case_num, i, j, l, switch_index, t_pos, p, q;
	char t;
	string input;

	cin >> n;
	cin.ignore();

	for(i=0; i<n ; i++)
	{
		cin >> case_num;
		cin >> input;

		l = input.length();

		switch_index = -1;
		for(j=(l-1); j>0 ; j--)
		{
			if(input[j] > input[j-1])
			{
				switch_index = (j-1);
				break;
			}
		}

		if(switch_index == -1)
		{
			cout << case_num << " " << "BIGGEST" << endl;
			continue;
		}

		t = input[switch_index + 1];
		t_pos = switch_index + 1;
		for(j=(switch_index + 1); j<l; j++)
		{
			if(input[j] < t && input[j] > input[switch_index])
			{
				t = input[j];
				t_pos = j;
			}
		}

		input[t_pos] = input[switch_index];
		input[switch_index] = t;

		for(p=(switch_index+1); p<(l-1); p++)
		{
			for(q=(switch_index+1); q<(l-1); q++)
			{
				if(input[q] > input[q+1])
				{
					t = input[q];
					input[q] = input[q+1];
					input[q+1] = t;
				}
			}
		}

		cout << case_num << " " << input << endl;
	}

	return 0;
}