#include<iostream>
using namespace std;

char board[51][51] = { 0, };
int n, m;

int CheckBoard(int x, int y)
{
	int minRes = 2147483647;

	int t = 2;
	while (t--)
	{
		int res = 0;
		char startColor = (t == 1 ? 'B' : 'W');

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int a = 0 % 2;
				bool flag1 = (j % 2 == 0) && (board[x + i][y + j] != startColor);
				bool flag2 = (j % 2 != 0) && (board[x + i][y + j] != (startColor == 'W' ? 'B' : 'W'));
				if (flag1 || flag2)
				{
					res++;
					continue;
				}
			}

			startColor = (startColor == 'W' ? 'B' : 'W');
		}

		if (res < minRes)
		{
			minRes = res;
		}
	}

	return minRes;
}

int main()
{
	cin >> n >> m;

	int minRes = 2147483647;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int j = 0; j <= m - 8; j++)
	{
		for (int i = 0; i <= n - 8; i++)
		{
			int num = CheckBoard(i, j);
			if (num < minRes)
			{
				minRes = num;
			}
		}
	}

	cout << minRes;
}

/*
9 8
WWWBBBWWWBBBWWWW
BBBWWBBBWBWWWWWW
WWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWW
WWWWBWWWWWWWWWWW
WWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWW
*/