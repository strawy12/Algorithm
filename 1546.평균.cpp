#include<iostream>
using namespace std;


int main()
{
	int n;
	int scores[1001];
	float allScore = 0;
	int maxScore = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> scores[i];

		if (scores[i] > maxScore)
		{
			maxScore = scores[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		allScore += (float)scores[i] / (float)maxScore * 100.f;
	}
	
	cout.precision(3);
	cout << (float)(allScore / (float)n);

}