#include <iostream>
#include <unordered_map>
#include <math.h>
using namespace std;

int arr[1000001] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		arr[i] = 1 + arr[i - 1];
		if (i % 3 == 0)
		{
			arr[i] = min(arr[i], 1 + arr[i / 3]);
		}

		if (i % 2 == 0)
		{
			arr[i] = min(arr[i], 1 + arr[i / 2]);
		}
	}

	cout << arr[n];

}