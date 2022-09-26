#include<iostream>
#include<math.h>
using namespace std;

double first, last;
double x1, x2;

double Func(double x)
{
	return (x * x * x) - (3 * x) + 1;
}

int main()
{
	cout << "���� ���� ����: ";
	cin >> first;

	cout << "������ ���� ����: ";
	cin >> last;

	x1 = Func(first);
	x2 = Func(last);

	int cnt = 0;
	
	while (x1 * x2 > 0)
	{
		// �������� �ø��� ���ؼ� �ѹ��� �ݺ��ϴ� ����
		if (cnt++ % 2 == 0)
		{
			last++;
		}
		else
		{
			first--;
		}

		x1 = Func(first);
		x2 = Func(last);
	}

	cout << first << " " << last << endl;

	while (last - first > 0.01) 
	{

		x1 = Func(first);
		x2 = Func(last);

		double mid = first + (last - first) * 0.5f;
		double value = Func(mid);
		

		if (value * x1 > 0)
		{
			first = mid;
		}

		else
		{
			last = mid;
		}

		if (last == first)
		{
			cout << value;
			break;
		}

	}

	cout << first << " " << last;
}