	#include <string>
	#include <vector>

	using namespace std;


	string solution(string new_id) {
		string answer = "";

		for (int i = 0; i < new_id.length(); i++)
		{
			char c = new_id[i];

			if ('0' <= c && c <= '9' && 'a' <= c && c <= 'z')
			{
				answer += c;
			}

			else if ('A' <= c && c <= 'Z')
			{
				answer += tolower(c);
			}

			else
			{
				switch (c)
				{
				case '.':
				{
					if (answer.size() != 0 && answer.back() == '.')
						continue;
					answer += c;
					break;
				}

				case '-':
				case '_':
					answer += c;
					break;

				case ' ':
					answer += 'a';
					break;
				}
			}

		}

		if (answer.front() == '.')
		{
			answer.erase(answer.begin());
		}

		if (answer.back() == '.')
		{
			answer.erase(answer.end() - 1);
		}

		if (answer.length() > 15)
		{
				answer.erase(answer.begin() + 15, answer.end());

			if (answer.back() == '.')
			{
				answer.erase(answer.end() - 1);
			}
		}

		else if (answer.length() < 3)
		{
			while (answer.length() < 3)
			{
				answer.push_back(answer.back());
			}
		}

		return answer;
	}