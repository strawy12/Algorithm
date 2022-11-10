#include<iostream>
#include <string>
#include <sstream>
using namespace std;

int parent[1000001];

int Find(int v)
{
	int temp = v;
	while (v != parent[v])
	{
		v = parent[v];
		
	}
	parent[temp] = v;

	return v;
}

void Union(int a,int b)
{
	int fa = Find(a);
	int fb = Find(b);

	if (fa != fb) parent[a] = b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	cin.ignore();

	for (int i = 0; i <= n; ++i)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		//string s;
		int a, b, c;

		//getline(cin, s);

		//stringstream ss;
		//ss.str(s);

		cin >> a >> b >> c;

		if (a == 0)
		{
			Union(b, c);
		}

		else
		{
			int fb = Find(b);
			int fc = Find(c);
			if (fb == fc)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}

}