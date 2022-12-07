#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

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
	unordered_set<int> s(ponketmonNums.begin(), ponketmonNums.end());

	
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

int solution(vector<int> nums)
{

	int answer = 0;

	int selectCnt = nums.size() / 2;

	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	int ponketmonCnt = nums.size();

	if (ponketmonCnt <= selectCnt)
	{
		answer = ponketmonCnt;
	}

	else
	{
		answer = selectCnt;
	}

	return answer;
}

