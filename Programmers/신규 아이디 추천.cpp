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

	string solution(string new_id) {
		string temp = "";

		// 1 �빮�� -> �ҹ���
		for (char& c : new_id)
		{
			if ('A' <= c && c <= 'Z')
			{
				c = tolower(c);
			}
		}
		
		// 2 Ư�� ���ڸ� ����
		for (char& c : new_id)
		{
			if (('a' <= c && c <= 'z') || // a - z ���� üũ
				('0' <= c && c <= '9') || // 0 - 9 ���� üũ
				(strchr("-_.", c)))       // -, _, . ���� üũ
			{
				temp += c; // �ش� ���ڰ� �´ٸ� ���� �־��ְ� �ƴϸ� ���� �ʾƼ� ���͸� ���ش�
			}
		}
		// ��ȯ�� �� ���� ��  temp���� �ʱ�ȭ
		new_id = temp;
		temp.clear();

		// 3 ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ� ����
		for (char& c : new_id) 
		{
			// ������� ���� ���¿��� �ٷ� ���� ���� . �ε� ���簪�� . �̸� ����ó��
			if (!temp.empty() && temp.back() == '.' && c == '.') continue;
			temp += c;
		}
		
		// 4 ��� �۾� �� �Ǿհ� �ڿ� .�� �ִٸ� ����
		if (temp.front() == '.') temp.erase(temp.begin());
		if (temp.back() == '.') temp.erase(temp.end() - 1);

		// 5 ���ڿ��� ����ִٸ� a ����
		if (temp.empty()) temp = "a";
		
		// 6 16���� �̻��̸� �� �ڴ� ����
		if (temp.size() >= 16) temp = temp.substr(0, 15);
		if (temp.back() == '.') temp.erase(temp.end() - 1);

		// 7 ���ڼ��� 3 ���ϸ� �� �� ���� �ݺ�
		while (temp.size() < 3)
		{
			temp += temp.back();
		}

		new_id = temp;

		return new_id;
	}
