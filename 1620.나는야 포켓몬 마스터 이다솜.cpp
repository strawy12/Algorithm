#include <iostream>
#include <string>
#include <Unordered_map>

using namespace std;

unordered_map<int, string> dictionaryNum;
unordered_map<string, int> dictionaryName;
string names[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string name;
		cin >> name;
		dictionaryNum[i] = name;
		dictionaryName[name] = i;
	}


	for (int i = 0; i < m; i++)
	{
		string name;
		cin >> names[i];
	}
	for (int i = 0; i < m; i++)
	{
		int num = 0;
		string name = names[i];

		if ('0' <= name[0] && name[0] <= '9')
		{
			num = stoi(name);
		}

		if (num == 0)
		{
			cout << dictionaryName[name] << '\n';
		}

		else
		{
			cout << dictionaryNum[num] << '\n';

		}
	}

}