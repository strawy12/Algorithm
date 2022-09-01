#include <string>
#include <vector>
#include <regex>

using namespace std;

// first code
int solution(string s) {
	int answer = 0;
	string s_Answer = "";

	for (int i = 0; i < s.length();)
	{
		char c = s[i];
		if ('0' <= c && c <= '9')
		{
			s_Answer += c;
		}
		else
		{
			switch (c)
			{
			case 'z':
				s_Answer += '0';
				i += 4;
				continue;

			case 'o':
				s_Answer += '1';
				i += 3;
				continue;

			case 't':
				if (s[i + 2] == 'o')
				{
					s_Answer += '2';
					i += 3;
				}

				else
				{
					s_Answer += '3';
					i += 5;
				}
				continue;

			case 'f':
				if (s[i + 3] == 'r')
				{
					s_Answer += '4';
					i += 4;
				}

				else
				{
					s_Answer += '5';
					i += 4;
				}
				continue;

			case 's':
				if (s[i + 2] == 'x')
				{
					s_Answer += '6';
					i += 3;
				}

				else
				{
					s_Answer += '7';
					i += 5;
				}

				continue;

			case 'e':
				s_Answer += '8';
				i += 5;
				continue;

			case 'n':
				s_Answer += '9';
				i += 4;
				continue;
			}
		}

		i++;
	}

	for (int i = 0; i < s_Answer.length(); i++)
	{
		int digit = s_Answer.length() - i;
		int pow = 1;
		for (int j = 1; j < digit; j++)
			pow *= 10;

		answer += (s_Answer[i] - '0') * pow;
	}

	return answer;
}

// after fix code
int solution(string s) {
	int answer = 0;
	string nums[10] = { 
		"zero","one","two","three","four",
		"five","six","seven","eight", "nine" };

	for (int i = 0; i < 10; i++)
	{
		size_t nPos = s.find(nums[i]);

		if (nPos != string::npos)
		{
			s = s.replace(nPos, nums[i].length(), to_string(i));
			i--;
		}
	}
	
	answer = stoi(s);
	return answer;
}

// 새롭게 알게된 방식
int solution(string s) {
	int answer = 0;
	string nums[10] = {
		"zero","one","two","three","four",
		"five","six","seven","eight", "nine" };

	for (int i = 0; i < 10; i++)
	{
		s = regex_replace(s, regex(nums[i]), to_string(i));
	}

	answer = stoi(s);
	return answer;
}
