#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> soldBooks;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string bookName;
		cin >> bookName;

		soldBooks[bookName]++;
 	}
	string bestSeller;
	int soldCnt = 0;

	for (auto book : soldBooks)
	{
		if (book.second > soldCnt)
		{
			soldCnt = book.second;
			bestSeller = book.first;
		}
	}

	cout << bestSeller << endl;
}