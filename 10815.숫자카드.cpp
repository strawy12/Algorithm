#include<iostream>
#include<unordered_set>
using namespace std;

unordered_set<int> us;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string ans = "";
	int n, m;


	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		us.insert(num);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		if (us.find(num) != us.end())
		{
			cout << 1 << ' ';
		}
		else
		{
			cout << 0 << ' ';
		}
	}
}