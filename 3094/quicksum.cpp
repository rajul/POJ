#include <iostream>

using namespace std;

int main()
{
	int i, l, sum;
	string input;

	while(1)
	{
		getline(cin, input);

		if(input.compare("#") == 0)
			break;

		l = input.length();
		sum = 0;

		for(i=0; i<l; i++)
		{
			if(input[i] != ' ')
			{
				sum = sum + (i+1) * (input[i] - 'A' + 1);
			}
		}

		cout << sum << endl;
	}

	return 0;
}
