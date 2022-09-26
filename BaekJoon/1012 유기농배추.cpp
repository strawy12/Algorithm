#include<iostream>
#include<cstring>
using namespace std;

int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };
int n, m, t, k, x, y, ret, ny, nx;
bool visited[51][51] = { 0, };
int farm[51][51] = { 0, };

void Find(int x, int y)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		nx = dx[i] + x;
		ny = dy[i] + y;

		if (nx < 0 || nx >= n || ny >= m || ny < 0)
			continue;

		if (visited[ny][nx] == false && farm[ny][nx] != 0)
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
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		ret = 0;
		cin >> n >> m >> k;

		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;

			farm[y][x] = 1;
		}

		for (int y = 0; y < m; y++)
		{
			for (int x = 0; x < n; x++)
			{
				if (!visited[y][x] && farm[y][x] != 0)
				{
					Find(x, y);
					ret++;
				}
			}
		}

		cout << ret << endl;

	}


}