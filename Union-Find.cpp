#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1001];

struct Edge
{
	int s;
	int e;
	int val;
	Edge(int a, int b, int c)
	{
		s = a;
		e = b;
		val = c;
	}

	bool operator<(const Edge& b) const {
		return val < b.val;
	}

	bool operator>(const Edge& b) const {
		return val > b.val;
	}
};

int Find(int v)
{
	if (parent[v] == v)
		return v;

	return Find(parent[v]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b) parent[b] = a;
}

//int main()
//{
//	int i, n, m, a, b, fa, fb, j;
//
//	cin >> n >> m; // n은 정점 수, m은 간선 쌍의 개수
//
//	for (int i = 1; i <= n; ++i)
//	{
//		parent[i] = i;
//	}
//
//	for (int i = 1; i <= m; ++i)
//	{
//		cin >> a >> b;
//		Union(a, b);
//	}
//
//	cin >> a >> b;
//	fa = Find(a);
//	fb = Find(b);
//
//	cout << ((fa == fb) ? "Yes" : "No") << endl;
//	return 0;
//}

int main()
{
	vector<Edge> Ed;
	int i, n, m, a, b, c, cnt = 0, res = 0;
	cin >> n >> m; // n은 정점 수, m은 간선 쌍의 개수

	for (int i = 1; i <= n; ++i)
	{
		parent[i] = i;
	}

	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b >> c;
		Ed.push_back(Edge(a, b, c));
	}

	sort(Ed.begin(), Ed.end());

	for (int i = 0; i < m; i++)
	{
		int fs = Find(Ed[i].s);
		int fe = Find(Ed[i].e);

		if (fs != fe)
		{
			Union(fs, fe);
			res += Ed[i].val;
		}
	}

	cout << res;
	return 0;
}

