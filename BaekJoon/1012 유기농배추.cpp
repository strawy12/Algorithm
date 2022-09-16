#include<iostream>
#include<cstring>
using namespace std;

int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };
int cnt = 0;
int n, m, t, k;
bool visited[51][51] = { 0, };
bool farm[51][51] = { 0, };

void Find(int x, int y)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || nx > n || ny > m || ny < 0)
			continue;

		if (visited[ny][nx] == false && farm[ny][nx] == true)
		{
			Find(nx, ny);
		}
	}
}

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		fill_n(farm[0], 51 * 51, 0);
		fill(&visited[0][0],&visited[0][0]+ 51 * 51, 0);
		cnt = 0;

		cin >> n >> m >> k;

		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;

			farm[y][x] = true;
		}

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (!visited[y][x] && farm[y][x])
				{
					Find(x, y);
					cnt++;
				}
			}
		}

		cout << cnt << endl;
		
	}


}