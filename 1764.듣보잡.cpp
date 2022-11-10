#include<iostream>
#include<set>
#include<unordered_set>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	unordered_set<string> us;
	set<string> ans;
	int i;
	string name;
	for ( i = 0; i < n; i++)
	{
		cin >> name;
		us.insert(name);
	}
	for ( i = 0; i < m; i++)
	{
		cin >> name;
		if (us.find(name) != us.end())
		{
			ans.insert(name);
		}
	}
	cout << ans.size() << '\n';

	for (auto listenP : ans)
	{
		cout << listenP << '\n';
	}


}