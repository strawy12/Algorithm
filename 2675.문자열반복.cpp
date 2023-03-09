#include<iostream>
#include<string>
using namespace std;

int main()
{
	int t;

	cin >> t;
	while (t--)
	{
		int r;
		string str;
		cin >> r;
		cin >> str;

		for (int i = 0; i < str.length(); i++)
		{
			for (int j = 0; j < r; j++)
			{
				cout << str[i];
			}
		}

		cout << endl;
	}

}