#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, bool> wordMap;

int main()
{
	int n;
	int cnt = 0;

	bool isGroup = false;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		char beforeChar = ' ';
		cin >> str;

		wordMap.clear();
		isGroup = true;
		for (int j = 0; j < str.size(); j++)
		{
			if (beforeChar == str[j])continue;

			beforeChar = str[j];

			if (wordMap[str[j]] == false)
			{
				wordMap[str[j]] = true;
				beforeChar = str[j];
			}
			else
			{
				isGroup = false;
				break;
			}
		}

		if (isGroup)
		{
			cnt++;
		}
	}

	cout << cnt;
}