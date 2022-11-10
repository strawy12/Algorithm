#include <iostream>
using namespace std;


int main()
{
	int n;
	int data;
	cin >> n;

	int arr[1001];

	for (int i = 0; i < n; i++)
	{
		cin >> data;
		arr[i] = data;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}

}