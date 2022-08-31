#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int beforeN = -1;

    for (int n : arr)
    {
        if (beforeN == n)
            continue;

        beforeN = n;
        answer.push_back(n);
    }

    return answer;
}