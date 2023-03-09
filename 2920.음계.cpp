#include<iostream>
using namespace std;

int main()
{
	int melody[8];

	// 0 == ascending
	// 1 == descending
	// 2 == mixed
	int type = 0;

	for (int i = 0; i < 8; i++)
	{
		cin >> melody[i];
	}

	if (melody[0] == 1)
	{
		type = 0;
	}

	else if (melody[0] == 8)
	{
		type = 1;
	}

	else
	{
		type = 2;
	}

	for (int i = 1; i < 8; i++)
	{
		if (type == 1 && melody[i] + 1 != melody[i - 1])
		{
			type = 2;
		}

		if (type == 0 && melody[i] - 1 != melody[i - 1])
		{
			type = 2;
		}
	}

	switch (type)
	{
	case 0:
		cout << "ascending";
		break;
	case 1:
		cout << "descending";
		break;
	case 2:
		cout << "mixed";
		break;
	}
}

