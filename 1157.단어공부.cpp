#include<iostream>
#include<unordered_map>
using namespace std;


int main()
{
	unordered_map<char, int> um;

	string str;
	cin >> str;

	for (char c : str)
	{
		um[toupper(c)]++;
	}

	pair<char, int> maxChar = { ' ', 0 };

	for (auto c : um)
	{
		if (c.second > maxChar.second)
		{
			maxChar = c;
		}

		else if (c.second == maxChar.second)
		{
			maxChar.first = '?';
		}
	}

	cout << (char)(maxChar.first != '?' ? toupper(maxChar.first) : maxChar.first);
}