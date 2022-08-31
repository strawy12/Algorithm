#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    int size = numbers.size() + 1;
    bool checkNum[10] = { false, };

    for (int n : numbers)
    {
        checkNum[n] = true;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (checkNum[i] == false)
        {
            answer += i;
        }
    }

    if (answer != -1)
    {
        answer += 1;
    }

    return answer;
}