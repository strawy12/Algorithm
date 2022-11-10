#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];
int temp[100001];
bool checkNums[100001];

void merge(int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge(left, mid);
		merge(mid + 1, right);

		int idx1 = left;
		int idx2 = mid + 1;

		int idx = left;

		while (idx1 <= mid && idx2 <= right)
		{
			if (arr[idx1] < arr[idx2])
			{
				temp[idx++] = arr[idx1++];
			}
			else
			{
				temp[idx++] = arr[idx2++];
			}
		}

		while (idx1 <= mid) temp[idx++] = arr[idx1++];
		while (idx2 <= right) temp[idx++] = arr[idx2++];

		for (int i = left; i <= right; i++)
		{
			arr[i] = temp[i];
		}
	} 
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	merge(0, n - 1);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		int left = 0, right = n - 1, mid;
		while (left <= right)
		{
			mid = (left + right) / 2;

			if (arr[mid] == num)
			{
				checkNums[i] = true;
				break;
			}

			else if (arr[mid] < num)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}

	}

	for (int i = 0; i < m; i++)
	{
		cout << checkNums[i] << " ";
	}


}