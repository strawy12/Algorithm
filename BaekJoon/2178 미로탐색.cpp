#include <iostream>
#include <queue>

using namespace std;
int arr[100][100] = { 0, };
int visited[100][100] = { 0, };
int n, m;
int main()
{

	cin >> n >> m;


	string input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = input[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	visited[0][0] = 1;
	q.push({ 0,0 });

	int dy[4]{ -1,0,1,0 };
	int dx[4]{ 0,1,0,-1 };

	while (q.size())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!((nx < m && nx >= 0) && (ny >= 0 && ny < n)) || visited[ny][nx] > 0 || arr[ny][nx] == 0)
			{
				continue;
			}

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}

	cout << visited[n - 1][m - 1];

	return 0;
}