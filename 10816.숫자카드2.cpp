#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<int, int> um;
int arr[500000] = { 0, };


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
		um[num]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		arr[i] = um[num];
	}

	for (int i = 0; i < m; i++)
	{
		cout << arr[i] << ' ';
	}
}