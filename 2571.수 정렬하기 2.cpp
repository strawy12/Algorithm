#include <iostream>
using namespace std;

int arr[1000001];
int temp[1000001];
void merge(int left, int right)
{
	
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge(left, mid);
		merge(mid+1, right);

		int p1 = left;
		int p2 = mid + 1;
		int idx = left;

		while (p1 <= mid && p2 <= right)
		{
			if (arr[p1] < arr[p2])
			{
				temp[idx] = arr[p1++];
			}

			else
			{
				temp[idx] = arr[p2++];
			}

			idx++;
		}

		while (p1 <= mid) temp[idx++] = arr[p1++];
		while (p2 <= right) temp[idx++] = arr[p2++];

		for (int i = left; i <= right; i++) 
		{
			arr[i] = temp[i];
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int data;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		//cin >> data;
		arr[i] = n - i;
	}

	merge(0, n -1);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\n';
	}
}