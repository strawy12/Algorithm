#include <string>
#include <vector>
#include <map>
#include <iostream>
#include<math.h>
// Programmers

using namespace std;
string solution(vector<string> survey, vector<int> choices);

int main()
{

	vector<string> vs = { "AN", "CF", "MJ", "RT", "NA" };
	vector<int> vi = { 5, 3, 2, 7, 5 };
	cout << solution(vs, vi);
}

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";
	map<char, int> map;
	char MBTI[4][2] =
	{
		{'R','T'},
		{'C','F'},
		{'J','M'},
		{'A','N'}
	};

	for (int i = 0; i < survey.size(); i++)
	{
		string s = survey[i];
		int choice = choices[i];

		if (choice < 4)
		{
			map[s[0]] += 4 - choice;
		}

		else
		{
			map[s[1]] += choice - 4;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		cout << map[MBTI[i][0]]<< " " << map[MBTI[i][1]] << endl;

		char c = map[MBTI[i][0]] >= map[MBTI[i][1]] ? MBTI[i][0] : MBTI[i][1];
		answer += c;
	}

	return answer;
}

