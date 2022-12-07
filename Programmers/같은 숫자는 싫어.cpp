#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

//first code
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

// 새롭게 알게된 방식
    vector<int> solution(vector<int> arr)
    {
        arr.erase(unique(arr.begin(), arr.end()), arr.end());

        vector<int> answer = arr;
        return answer;
    }