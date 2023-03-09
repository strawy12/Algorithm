#include<iostream>
using namespace std;

int main()
{
	int alphabets[26]{ 0, };
	string word;
	cin >> word;

	for (int i = 0; i < word.length(); i++)
	{
		if (alphabets[(int)(word[i] - 'a')] - 1 == -1)
		{
			alphabets[(int)(word[i] - 'a')] = i + 1;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alphabets[i] - 1 << " ";
	}
}