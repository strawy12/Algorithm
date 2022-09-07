	#include <string>
	#include <vector>
	#include <algorithm>

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

	string solution(string new_id) {
		string temp = "";

		// 1 대문자 -> 소문자
		transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
		
		// 2 특정 글자만 유지
		for (char& c : new_id)
		{
			if (('a' <= c && c <= 'z') || // a - z 인지 체크
				('0' <= c && c <= '9') || // 0 - 9 인지 체크
				(strchr("-_.", c)))       // -, _, . 인지 체크
			{
				temp += c; // 해당 글자가 맞다면 값을 넣어주고 아니면 넣지 않아서 필터링 해준다
			}
		}
		// 변환한 값 대입 후  temp변수 초기화
		new_id = temp;	
		temp.clear();

		// 3 마침표(.)가 2번 이상 연속된 부분 삭제
		for (char& c : new_id) 
		{
			// 비어있지 않은 상태에서 바로 전의 값이 . 인데 현재값도 . 이면 예외처리
			if (!temp.empty() && temp.back() == '.' && c == '.') continue;
			temp += c;
		}
		
		// 4 모든 작업 후 맨앞과 뒤에 .이 있다면 삭제
			if (temp.front() == '.') temp.erase(temp.begin());
			if (temp.back() == '.') temp.erase(temp.end() - 1);

		// 5 문자열이 비어있다면 a 대입
		if (temp.empty()) temp = "a";
		
		// 6 16글자 이상이면 그 뒤는 삭제
		if (temp.size() >= 16) temp = temp.substr(0, 15);
		if (temp.back() == '.') temp.erase(temp.end() - 1);

		// 7 글자수가 3 이하면 맨 끝 문자 반복
		while (temp.size() < 3)
		{
			temp += temp.back();
		}

		new_id = temp;

		return new_id;
	}
