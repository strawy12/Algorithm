#include <iostream>

using namespace std;


long long arr[101] = { 0,1,1,1,2,2, };

long long Padovan(long long n)
{
	if (arr[n] != 0)
	{
		return arr[n];
	}

	long long a = Padovan(n - 1);
	long long b = Padovan(n - 5);
	long long ret = a + b;
	arr[n] = ret;
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		cout << Padovan(n) << "\n";
	}
}
