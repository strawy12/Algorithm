#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums);
void main()
{
    auto a = solution({ 1, 2, 3, 4, 5, 6 }, { 7, 8, 9, 10, 11, 12 });
    cout << a[0] << " " << a[1];
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {

    int containCnt = 0;
    int invisableCnt = 0;

    for (int n : lottos)
    {
        if (n == 0)
        {
            invisableCnt++;
            continue;
        }

        for (int wn : win_nums)
        {
            if (n == wn)
            {
                containCnt++;
                break;
            }
        }
    }

    // 전체 맞아야하는 갯수 - 맞은 갯수 + 1 = 순위
    // 6개 맞았다면 -> 6 - 6 + 1 = 1위
    // 5개 맞았다면 -> 6 - 5 + 1 = 2위
    // 4개 맞았다면 -> 6 - 4 + 1 = 3위
    // 3개 맞았다면 -> 6 - 3 + 1 = 4위
    // 2개 맞았다면 -> 6 - 2 + 1 = 5위

    // 전체 맞아야하는 갯수 - 맞은 갯수(나머지는 모두 안 맞았다는 가정) + 1 = 순위
    int minRank = (6 - containCnt) + 1;

    // 1개 이하 맞으면 무조건 6위(낙첨)
    minRank = minRank > 6 ? 6 : minRank;

    // 전체 맞아야하는 갯수 - 맞은 갯수(나머지는 모두 맞았다는 가정) + 1 = 순위
    int maxRank = (6 - (containCnt + invisableCnt)) + 1;
    minRank = minRank > 6 ? 6 : minRank;
    maxRank = maxRank > 6 ? 6 : maxRank;

    return vector<int> {maxRank, minRank};
}