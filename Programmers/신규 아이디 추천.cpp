#include <string>
#include <vector>

using namespace std;

string solution(string new_id);
string ReplaceCapitalToSmall(string new_id);
string LimitChar(string new_id);
string ReduplicationFullstop(string new_id);
string FirstLastCheck(string new_id);
string NullCheck(string new_id);
string CharacterNumLimit(string new_id);
string MinimumCharacterLimit(string new_id);


string solution(string new_id) {
	string answer = ReplaceCapitalToSmall(new_id);
	answer = LimitChar(answer);
	answer = ReduplicationFullstop(answer);
	answer = FirstLastCheck(answer);
	answer = NullCheck(answer);
	answer = CharacterNumLimit(answer);
	answer = MinimumCharacterLimit(answer);
	return answer;
}

string ReplaceCapitalToSmall(string new_id)
{
	for (int i = 0; i < new_id.length(); i++)
	{
		if ('A' <= new_id[i] && new_id[i] <= 'Z')
		{
			new_id[i] += 32;
		}
	}


	return new_id;
}

string LimitChar(string new_id)
{

	string result = "";
	for (int i = 0; i < new_id.length(); i++)
	{
		if ('a' <= new_id[i] && new_id[i] <= 'z')
		{
			result += new_id[i];
		}

		if ('0' <= new_id[i] && new_id[i] <= '9')
		{
			result += new_id[i];
		}

		if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
		{
			result += new_id[i];
		}
	}


	return result;
}

string ReduplicationFullstop(string new_id)
{

	string result = "";

	for (int i = 0; i < new_id.length(); i++)
	{
		if (new_id[i] == '.')
		{
			if (new_id[i + 1] == '.')
			{
				int j = 0;
				for (j = i; j < new_id.length(); j++)
				{
					if (new_id[j] != '.')
					{
						break;
					}
				}

				i = j - 1;
			}
		}


		result += new_id[i];
	}


	return result;
}

string FirstLastCheck(string new_id)
{
	string result = "";

	for (int i = 0; i < new_id.length(); i++)
	{
		if (new_id[i] == '.' && (i == 0 || i == new_id.length() - 1))
		{

			continue;
		}

		result += new_id[i];
	}


	return result;
}

string NullCheck(string new_id)
{

	if (new_id == "")
	{
		new_id = "a";
	}


	return new_id;
}

//6´Ü°è Â÷·Ê
string CharacterNumLimit(string new_id)
{
	if (new_id.length() > 15)
	{
		string result = "";
		for (int i = 0; i < 15; i++)
		{
			result += new_id[i];
		}
		new_id = result;
	}
	new_id = FirstLastCheck(new_id);

	return new_id;
}

string MinimumCharacterLimit(string new_id)
{
	if (new_id.length() < 3)
	{
		char retChar = new_id[new_id.length() - 1];
		for (int i = 0; new_id.length() < 3; i++)
		{
			new_id = new_id + retChar;
		}
	}


	return new_id;
}