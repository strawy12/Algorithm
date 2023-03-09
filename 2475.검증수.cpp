#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    map<char, int> m;
    int a, b, c;
    cin >> a >> b >> c;

    string s = to_string(a * b * c);

    for (int i = 0; i < 10; i++)
    {
        m['0' + i] = 0;
    }

    for (int i = 0; i < s.length(); i++) 
    {
        m[s[i]]++;
    }

    for (auto p : m)
    {
        cout << p.second << endl;
    }

}