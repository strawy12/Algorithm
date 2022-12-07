#include <iostream>
using namespace std;
int main()
{
    long long total, win, winningRate, newR, mid, ans;
    cin >> total >> win;
    winningRate = win * 100 / total;
    long long left = 1;
    long long right = total;

    if (winningRate >= 99)
    {
        cout << -1;
        return 0;
    }

    while (left <= right)
    {
        mid = (left + right) / 2;
        newR = (win + mid) * 100 / (total + mid);

        if (newR > winningRate)
        {
            right = mid - 1;
            
        }
        else
        {
            left = mid + 1;
        
        }
    }
    cout << left;
}