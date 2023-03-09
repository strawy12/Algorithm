#include<iostream>
using namespace std;

int main()
{
	int min = INT_MAX, max = INT_MIN;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (num < min)
		{
			min = num;
		}

		if (num > max)
		{
			max = num;
		}
	}

	cout << min << " " << max;
}