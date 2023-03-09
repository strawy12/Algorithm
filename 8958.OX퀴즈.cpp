#include<iostream>
#include<string>
using namespace std;

int main()
{
	int t;

	cin >> t;

	while (t--)
	{
		string str;
		cin >> str;

		int res = 0;
		int stack = 0;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 'O')
			{
				res += stack + 1;
				stack++;
			}

			if (str[i] == 'X')
			{
				stack = 0;
			}
		}

		cout << res << endl;
	}
}