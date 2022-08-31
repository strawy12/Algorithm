#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

struct POINT
{
    int x;
    int y;
};
string solution(vector<int> numbers, string hand);
int main()
{
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    cout << solution(nums, "right");
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    vector<POINT> keypad =
    {
        {1,3},
        {0,0},
        {1,0},
        {2,0},
        {0,1},
        {1,1},
        {2,1},
        {0,2},
        {1,2},
        {2,2}
    };

    POINT leftHand = { 0,3 };
    POINT rightHand = { 2,3 };

    for (int n : numbers)
    {
        if (n != 0 && n % 3 == 0)
        {
            answer += 'R';
            rightHand = keypad[n];
        }
        else if (n != 0 && n % 3 == 1)
        {
            answer += 'L';
            leftHand = keypad[n];
        }
        else
        {
            int left = abs(keypad[n].x - leftHand.x) + abs(keypad[n].y - leftHand.y);
            int right = abs(keypad[n].x - rightHand.x) + abs(keypad[n].y - rightHand.y);

            if (left < right)
            {
                answer += 'L';
                leftHand = keypad[n];
            }
            else if (left == right)
            {
                if (hand == "right")
                {
                    answer += 'R';
                    rightHand = keypad[n];
                }

                else
                {
                    answer += 'L';
                    leftHand = keypad[n];
                }
            }
            else
            {
                answer += 'R';
                rightHand = keypad[n];
            }
        }
    }

    return answer;
}