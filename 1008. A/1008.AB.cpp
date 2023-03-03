#include<iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    cout.precision(11);
    cout << (double)a / b;
}