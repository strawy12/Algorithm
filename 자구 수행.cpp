#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//#define MAX_VTXS 256
//
//class AdjMatGraph
//{
//protected:
//	int size;
//	char vertices[MAX_VTXS];
//	int adj[MAX_VTXS][MAX_VTXS];
//
//public:
//	AdjMatGraph() { reset(); }
//
//	char getVertex(int i) { return vertices[i]; }
//	int getEdge(int i, int j) { return adj[i][j]; }
//	void setEdge(int i, int j, int val) { adj[i][j] = val; }
//	bool isEmpty() { return size == 0; }
//	bool isFull() { return size >= MAX_VTXS; }
//
//	void reset()
//	{
//		size = 0;
//		for (int i = 0; i < MAX_VTXS; i++)
//		{
//			for (int j = 0; j < MAX_VTXS; j++)
//			{
//				setEdge(i, j, 0);
//			}
//		}
//	}
//
//	void insertVertex(char name)
//	{
//		vertices[size++] = name;
//	}
//
//	void insertEdge(int u, int v)
//	{
//		setEdge(u, v, 1);
//		setEdge(v, u, 1);
//	}
//
//	void display()
//	{
//		cout << "정점의 개수 : " << size << endl;
//		for (int i = 0; i < size; i++)
//		{
//			cout << vertices[i] << " ";
//
//			for (int j = 0; j < size; j++)
//			{
//				cout << getEdge(i, j) << " ";
//			}
//
//			cout << endl;
//		}
//	}
//};
//
//class SearchGraph : public AdjMatGraph
//{
//	int visited[MAX_VTXS];
//
//public:
//	void resetVisited()
//	{
//		for (int i = 0; i < size; i++)
//		{
//			visited[i] = false;
//		}
//	}
//
//	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }
//	
//	void DFS(int v)
//	{
//		visited[v] = true;
//		cout << vertices[v] << " ";
//
//		for (int i = 0; i < size; i++)
//		{
//			if (isLinked(i, v) && visited[i] == false)
//			{
//				DFS(i);
//			}
//		}
//	}
//
//	void BFS(int v)
//	{
//		fill_n(visited, MAX_VTXS, -1);
//		visited[v] = 0;
//		queue<char> q;
//		q.push(v);
//
//		while (q.empty() == false)
//		{
//			int i = q.front();
//			cout << getVertex(i) << " ";
//			q.pop();
//
//			for (int j = 0; j < size; j++)
//			{
//				if (isLinked(j, i) && visited[j] < 0)
//				{
//
//					visited[j] = visited[i] + 1;
//					q.push(j);
//				}
//			}
//		}
//		cout << endl << "A에서 각 정점까지의 거리 : ";
//		for (int i = 0; i < size; i++)
//		{
//			cout << visited[i] << " ";
//		}
//	}
//};
//
//int main()
//{
//	SearchGraph g;
//
//	for (int i = 0; i < 4; i++)
//	{
//		g.insertVertex('A' + i);
//	}
//
//	g.insertEdge(0, 1);
//	g.insertEdge(0, 3);
//	g.insertEdge(1, 2);
//	g.insertEdge(1, 3);
//	g.insertEdge(2, 3);
//
//	cout << "인접 행렬로 표현한 그래프" << endl;
//	g.display();
//	cout << "DFS 탐색 => ";
//	g.resetVisited();
//	g.DFS(0);
//	cout << endl;
//	cout << "BFS 탐색 => ";
//	g.resetVisited();
//	g.BFS(0);
//}

//const int MAX = 100;
//int n, m, a[MAX][MAX], visited[MAX][MAX];
//
//int main()
//{
//	cin >> n >> m;
//	string temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < m; j++)
//		{
//			a[i][j] = temp[j] - '0';
//		}
//	}
//
//	int dy[4] = { -1,0,1,0 };
//	int dx[4] = { 0,1,0,-1 };
//
//	queue<pair<int, int>> q;
//	visited[0][0] = 1;
//	q.push({ 0,0 });
//
//	while (q.empty() == false)
//	{
//		int x = q.front().first;
//		int y = q.front().second;
//		q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = dx[i] + x;
//			int ny = dy[i] + y;
//
//			if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
//
//			if (a[ny][nx] != 0 && visited[ny][nx] < 1)
//			{
//				visited[ny][nx] = visited[y][x] + 1;
//				q.push({ nx, ny });
//			}
//		}
//	}
//
//	cout << visited[n - 1][m - 1];
//}

//int dy[4] = { -1,0,1,0 };
//int dx[4] = { 0,1,0,-1 };
//int m, n, k, y, x, ret, ny, nx, t;
//int a[51][51];
//bool visited[51][51];
//
//void dfs(int y, int x)
//{
//	visited[y][x] = 1;
//	for (int i = 0; i < 4; i++)
//	{
//		ny = y + dy[i];
//		nx = x + dx[i];
//
//		if (nx >= m || nx < 0 || ny >= n || ny < 0)continue;
//		if (a[ny][nx] == 1 && !visited[ny][nx])
//		{
//			visited[ny][nx] = true;
//			dfs(ny, nx);
//		}
//	}
//}
//
//int main()
//{
//	cin >> t;
//	while (t--)
//	{
//		fill_n(a[0], 51 * 51, 0);
//		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
//		ret = 0;
//		cin >> m >> n >> k;
//
//		for (int i = 0; i < k; i++)
//		{
//			cin >> x >> y;
//			a[y][x] = 1;
//		}
//
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				if (a[i][j] == 1 && !visited[i][j])
//				{
//					dfs(i, j);
//					ret++;
//				}
//			}
//		}
//
//		cout << ret << endl;
//	}
//}

//int parent[1001];
//
//int Find(int v)
//{
//	if (v == parent[v])
//		return v;
//
//	return Find(parent[v]);
//}
//
//void Union(int a, int b)
//{
//	a = Find(a);
//	b = Find(b);
//	if (a != b) parent[b] = a;
//}
//
//int main()
//{
//	int i, n, m, a, b, fa, fb, j;
//	cin >> n >> m;
//	for (i = 1; i <= n; i++)
//	{
//		parent[i] = i;
//	}
//	for (i = 1; i <= m; i++)
//	{
//		cin >> a >> b;
//		Union(a, b);
//	}
//
//	cin >> a >> b;
//	fa = Find(a);
//	fb = Find(b);
//	if (fa == fb) cout << "YES";
//	else cout << "NO";
//}

//struct Edge
//{
//	int e;
//	int s;
//	int val;
//
//	Edge(int a, int b, int c)
//	{
//		e = a;
//		s = b;
//		val = c;
//	}
//
//	bool operator<(const Edge& b) const
//	{
//		return val < b.val;
//	}
//};
//
//int parent[1001];
//
//int Find(int v)
//{
//	if (v == parent[v])
//		return v;
//
//	return Find(parent[v]);
//}
//
//void Union(int a, int b)
//{
//	int fa = Find(a);
//	int fb = Find(b);
//
//	if (fa != fb) parent[b] = a;
//}
//
//int main()
//{
//	vector<Edge> Ed;
//	int n, m;
//	int result = 0;
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		parent[i] = i;
//	}
//	
//	for (int i = 0; i < m; i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//
//		Ed.push_back(Edge(a, b, c));
//	}
//
//	sort(Ed.begin(), Ed.end());
//
//	for (int i = 0; i < m; i++)
//	{
//		int fa = Find(Ed[i].e);
//		int fb = Find(Ed[i].s);
//
//		if (fa != fb)
//		{
//			Union(fa, fb);
//			result += Ed[i].val;
//		}
//	}
//
//	cout << result;
//}

struct Edge
{
	int e;
	int s;
	int val;

	Edge(int a, int b, int c)
	{
		e = a;
		s = b;
		val = c;
	}

	bool operator<(const Edge& b) const
	{
		return val < b.val;
	}
};

int parent[1001];

int Find(int v)
{
	if (v == parent[v])
	{
		return v;
	}

	return Find(parent[v]);
}

void Union(int a, int b)
{
	int fa = Find(a);
	int fb = Find(b);
	if (fa != fb) parent[b] = a;
}

int main()
{
	vector<Edge> Ed;
	int n, m;
	int result = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Ed.push_back(Edge(a, b, c));
	}

	sort(Ed.begin(), Ed.end());

	for (int i = 0; i < m; i++)
	{
		int fa = Find(Ed[i].e);
		int fb = Find(Ed[i].s);

		if (fa != fb)
		{
			Union(fa, fb);
			result += Ed[i].val;
		}
	}

	cout << result;
}
