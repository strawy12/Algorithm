#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<string> userVecs[201];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int age;
		string name;

		cin >> age >> name;

		userVecs[age].push(name);
	}

	for (int i = 1; i <= 200; i++)
	{
		while(userVecs[i].size() != 0)
		{
			cout << i << " " << userVecs[i].front() << '\n';
			userVecs[i].pop();
		}
	}
}
