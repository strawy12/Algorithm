#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums);
bool ComperePonketMon(int num, vector<int>& vPonketmon);

int main()
{
	vector<int> vi = { 3, 3, 3, 2, 2, 2 };
	cout << solution(vi);
}


int solution(vector<int> nums)
{
    int answer = 0;
	vector<int> ponketmonNums;

	int selectCnt = nums.size() / 2;

	int ponketmonCnt = 0;

	for (int n : nums)
	{
		if (ComperePonketMon(n, ponketmonNums))
			continue;

		ponketmonNums.push_back(n);
		ponketmonCnt++;
	}

	cout << ponketmonCnt << " " << selectCnt<<endl;

	if (ponketmonCnt > selectCnt)
	{
		answer = selectCnt;
	}

	else
	{
		answer = ponketmonCnt;
	}

    return answer;
}

bool ComperePonketMon(int num, vector<int>& vPonketmon)
{
	for (int p : vPonketmon)
	{
		if (p == num)
			return true;
	}

	return false;
}