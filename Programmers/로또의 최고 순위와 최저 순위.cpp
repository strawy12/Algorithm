#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;


vector<int> solution(vector<int> lottos, vector<int> win_nums) {

    int cnt = 0;
    int zeroCnt = 0;
    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            zeroCnt++;
            continue;
        }

        for (int j = 0; j < win_nums.size(); j++)
        {
            if (lottos[i] == win_nums[j])
            {
                cnt++;
                win_nums.erase(win_nums.begin() + j);
            }
        }

    }

    int minRank, maxRank;

    if (cnt < 2)
    {
        minRank = 6;
    }

    else
    {
        minRank = 6 - cnt + 1;
    }

    if (zeroCnt + cnt < 2)
    {
        maxRank = 6;
    }

    else
    {
        maxRank = 6 - (zeroCnt + cnt) + 1;
    }

    vector<int> answer;
    answer.push_back(maxRank);
    answer.push_back(minRank);

    return answer;
}