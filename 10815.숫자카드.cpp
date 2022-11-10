#include<iostream>
#include<unordered_set>
using namespace std;

unordered_set<int> us;
bool arr[500000] = { false, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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
			arr[i] = true;
		}
	}

	for (int i = 0; i < m; i++)
	{
		cout << arr[i] << ' ';
	}
}