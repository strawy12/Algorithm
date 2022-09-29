#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
#define MAX_VTXS 256
#define INFINITE 9999

class AdjMatGraph
{
protected:
	int size;
	char vertices[MAX_VTXS];
	int adj[MAX_VTXS][MAX_VTXS];

public:
	AdjMatGraph() { reset(); }

	void insertVertex(char name) { vertices[size] = name; size++; }
	void insertEdge(int u, int v, int dist) { setEdge(u, v, dist); setEdge(v, u, dist); }

	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }
	void reset()
	{
		size = 0;

		for (int i = 0; i < MAX_VTXS; i++)
			for (int j = 0; j < MAX_VTXS; j++)
				setEdge(i, j, INFINITE);
	}


	void display()
	{
		int i = 0;
		int j = 0;
		cout << "정점의 개수 : " << size << endl;

		for (i; i < size; i++)
		{
			cout << getVertex(i) << "\t";

			for (j = 0; j < size; j++)
			{
				cout << getEdge(i, j) << " ";
			}
			cout << endl;
		}
	}
};
class SearchGraph : public AdjMatGraph
{
	int visited[MAX_VTXS];

public:
	void resetVisited()
	{
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}
	}

	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	void DFS(int v)
	{
		if (visited[v]) return;

		cout << getVertex(v) << " ";
		visited[v] = true;
		for (int i = 0; i < size; i++)
		{
			if (isLinked(v, i))
			{
				DFS(i);
			}
		}

	}

	void BFS(int v)
	{
		fill_n(visited, MAX_VTXS, -1);
		visited[v] = 0;

		queue<char> q;
		q.push(v);

		while (!q.empty())
		{
			int iv = q.front();
			cout << getVertex(iv) << " ";
			q.pop();

			for (int i = 0; i < size; i++)
			{
				if (isLinked(iv, i) && visited[i] < 0)
				{
					visited[i] = visited[iv] + 1;
					q.push(i);
				}
			}
		}

		cout << endl << "A에서 각 정점까지의 거리 : ";
		for (int i = 0; i < size; i++)
		{
			cout << " " << visited[i];
		}
	}
};
class ShortestGragh : public AdjMatGraph
{
	int dist[MAX_VTXS];
	bool founds[MAX_VTXS];
	int parent[MAX_VTXS];

public:
	void printDist()
	{
		for (int i = 0; i < size; i++)
		{
			if (dist[i] == INFINITE)
			{
				cout << "I ";
			}

			else
			{
				cout << dist[i] << " ";
			}
		}
		cout << endl;
	}

	int chooseVertex()
	{
		int min = 9999;
		int minPos = -1;
		for (int i = 0; i < size; i++)
		{
			if (!founds[i] && dist[i] < min)
			{
				min = dist[i];
				minPos = i;
			}
		}

		return minPos;
	}

	void dijikstra(int start, int end)
	{
		for (int i = 0; i < size; i++)
		{
			dist[i] = getEdge(start, i);
			founds[i] = false;
		}
		fill_n(parent, size, -1);
		founds[start] = true;
		dist[start] = 0;
		parent[start] = start;

		int next = -1, current = start;


		for (int i = 0; i < size; i++)
		{
			if (next == end)
			{
				cout << "목적 정점 " << end << "에 도착!" << endl;
				break;
			}

			cout << "Step " << i + 1 << " : ";
			printDist();
			next = chooseVertex();

			if (i == 0)
			{
				parent[next] = start;

			}

			cout << current << "정점에서 시작!" << endl;
			founds[next] = true;

			for (int w = 0; w < size; w++)
			{
				if (!founds[w])
					if (dist[next] + getEdge(next, w) < dist[w])
					{
						dist[w] = dist[next] + getEdge(next, w);
						parent[w] = next;

					}
			}
			current = next;
		}
	}

	void PrintPath(int start, int target)
	{
		if (start == target)
		{
			cout << "최단 경로는 " << start;
			return;
		}
		PrintPath(start, parent[target]);
		cout << " " << target;

	}


};

int main()
{
	ShortestGragh g;

	g.reset();

	for (int i = 0; i < 4; i++)
		g.insertVertex('A' + i);

	g.insertEdge(0, 1, 2); // A B : 1
	g.insertEdge(0, 2, 7);
	g.insertEdge(1, 2, 1);
	g.insertEdge(1, 3, 3);
	g.insertEdge(3, 2, 2);

	//cout << "인접 행렬로 표현한 그래프" << endl;
	//g.display();
	g.dijikstra(0, 2);
}

//class AdjMatGraph
//{
//protected:
//	vector<char> vertices;
//	vector<int> adj;
//
//public:
//	AdjMatGraph() { reset(); }
//
//	char getVertex(int i) { return vertices[i]; }
//	int getEdge(int i, int j) 
//	{ 
//		return adj[i * getSize() + j];
//	}
//	void setEdge(int i, int j, int val) 
//	{ 
//		int idx1 = i * getSize() + j;
//		int idx2 = j * getSize() + i;
//		adj[idx1] = adj[idx2] = val;
//	}
//	int getSize() { return vertices.size(); }
//	bool isEmpty() { return getSize() == 0; }
//	bool isFull() { return getSize() == MAX_VTXS; }
//
//	void reset()
//	{
//		vertices.clear();
//		adj.clear();
//	}
//
//	void insertVertex(char name)
//	{
//		vertices.push_back(name);
//		adj.resize(getSize() * getSize());
//	}
//
//	void insertEdge(int u, int v)
//	{
//		setEdge(u, v, 1);
//	}
//
//	void display()
//	{
//		cout << "정점의 갯수: " << getSize() << endl;
//		for (int i = 0; i < getSize(); i++)
//		{
//			cout << getVertex(i) << " ";
//			for (int j = 0; j < getSize(); j++)
//			{
//				cout << getEdge(i,j) << " ";
//			}
//
//			cout << endl;
//		}
//	}
//};
//
//int main()
//{
//	AdjMatGraph amg;
//
//	for (int i = 0; i < 4; i++)
//	{
//		amg.insertVertex('A' + i);
//	}
//
//	amg.insertEdge(0, 1);
//	amg.insertEdge(0, 3);
//	amg.insertEdge(1, 2);
//	amg.insertEdge(1, 3);
//	amg.insertEdge(2, 3);
//
//	cout << "인접 행렬로 표현한 그래프" << endl;
//	amg.display();
//}