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

    // ��ü �¾ƾ��ϴ� ���� - ���� ���� + 1 = ����
    // 6�� �¾Ҵٸ� -> 6 - 6 + 1 = 1��
    // 5�� �¾Ҵٸ� -> 6 - 5 + 1 = 2��
    // 4�� �¾Ҵٸ� -> 6 - 4 + 1 = 3��
    // 3�� �¾Ҵٸ� -> 6 - 3 + 1 = 4��
    // 2�� �¾Ҵٸ� -> 6 - 2 + 1 = 5��

    // ��ü �¾ƾ��ϴ� ���� - ���� ����(�������� ��� �� �¾Ҵٴ� ����) + 1 = ����
    int minRank = (6 - containCnt) + 1;

    // 1�� ���� ������ ������ 6��(��÷)
    minRank = minRank > 6 ? 6 : minRank;

    // ��ü �¾ƾ��ϴ� ���� - ���� ����(�������� ��� �¾Ҵٴ� ����) + 1 = ����
    int maxRank = (6 - (containCnt + invisableCnt)) + 1;
    minRank = minRank > 6 ? 6 : minRank;
    maxRank = maxRank > 6 ? 6 : maxRank;

    return vector<int> {maxRank, minRank};
}