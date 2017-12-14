#include <iostream>

using namespace std;

int count_insertions_to_make_palindrome(string s, int n) 
{
	int i, start, end, count = 0;

	start = 0;
	end = n - 1;

	for(i = 0; i < (end / 2); i++)
	{
		if(s[start] != s[end])
			count = count + 2;

		start++;
		end--;
	}

	if(n % 2 == 0)
	{
		if(s[start] != s[end])
			count++;
	}

	return count;
}


int main()
{
	int n;
	string name;

	cin >> n;
	cin >> name;
	cout << count_insertions_to_make_palindrome(name, n) << endl;

	return 0;
}