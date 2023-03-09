#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main()
{
	string str1, str2;

	cin >> str1 >> str2;
	
	string num1= "", num2 = "";
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		num1 += str1[i];
	}

	for (int i = str2.length() - 1; i >= 0; i--)
	{
		num2 += str2[i];
	}

	int num = max(stoi(num1), stoi(num2));
	cout << num;
}