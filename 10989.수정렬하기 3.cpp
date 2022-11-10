#include <iostream>
using namespace std;

int cnt[10001] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 10000000;
	//cin >> n;

	int data;

	for (int i = 0; i < n; i++)
	{
		//cin >> data;
		data = 10000;
		cnt[data]++;
	}

	for (int i = 0; i <= 10000; i++)
	{
		while (cnt[i] > 0)
		{
			cnt[i]--;
			cout << i << '\n';
		}
	}
}