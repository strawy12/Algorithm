#include <string>
#include <vector>
#include<iostream>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> basket;

	for (int n : moves)
	{
		int doll = 0;
		for (int i = 0; i < board.size(); i++)
		{
			if (board[i][n - 1] != 0)
			{
				doll = board[i][n - 1];
				board[i][n - 1] = 0;
				break;
			}
		}

		if (doll == 0)
			continue;

		if (!basket.empty() && basket.top() == doll)
		{
			basket.pop();
			answer+=2;
		}

		else
		{
			basket.push(doll);
		}
	}




	return answer;
}



int main()
{
	vector<vector<int>> board = 
	{   {0, 0, 0, 0, 0},
		{0, 0, 1, 0, 3},
		{0, 2, 5, 0, 1},
		{4, 2, 4, 4, 2},
		{3, 5, 1, 3, 1} };

	//4311324
	vector<int> moves = { 1,5,3,5,1,2,1,4 };

	cout << solution(board, moves);
}