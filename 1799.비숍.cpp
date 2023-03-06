#include<iostream>
#include<math.h>

using namespace std;

// 해당 문제는 다시 한번 풀어보기로 한다

int n;
int res = 0;
int chessBoard[11][11] = { 0, };

bool visited1[20];
bool visited2[20];

// color: 1 = black, 0 = white
int CheckBishop(int idx, int cnt, int color)
{
	if (idx >= n * n)
		return;

	for (int i = idx; i < n * n; i++)
	{
		int x = i / n;
		int y = i % n;

		if (!color && (x + y) % 2 != 0) continue;
		else if (color && (x + y) % 2 == 0) continue;

		if(chessBoard[x][y] == 0) continue;
		if (visited1[x + y])continue;
		if (visited2[x - y + n])continue;

		visited1[x + y] = true;
		visited2[x - y + n] = true;
		res = max(res, cnt + 1);
		CheckBishop(i + 1, cnt + 1, color);
		visited1[x + y] = false;
		visited2[x - y + n] = false;
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> chessBoard[i][j];
		}
	}

	CheckBishop(0, 0, 0);
	int temp = res;
	res = 0;
	CheckBishop(1, 0, 1);

	cout << res + temp;
}