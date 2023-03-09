#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
	unordered_set<int> us;

	for (int i = 0; i < 10; i++)
	{
		int num;
		cin >> num;

		us.insert(num % 42);
	}

	cout << us.size();
}

