//ù° �ٿ� N�� X�� �־�����. 
#include<iostream>
#include<vector>
using namespace std;

int main()
{

	int n, x;
	vector<int> v;

	cin >> n >> x;

	for (int i = 0; i < n; i++)
	{
	    int num;

	    cin >> num;

	    if (num < x)
	    { 
	        v.push_back(num);
	    }
	}

	for (int i = 0; i < v.size(); i++)
	{
	    cout << v[i] << ' ';
	}
}