//
//#include<iostream>
//#include<unordered_map>
//using namespace std;
//
//unordered_map<int, int> um;
//
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n, m;
//
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int num;
//		cin >> num;
//		um[num]++;
//	}
//
//	cin >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int num;
//		cin >> num;
//		cout << um[num] << ' ';
//	}
//
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n, m;
//	vector<int> nums;
//	vector<int> answers;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int num;
//		cin >> num;
//		nums.push_back(num);
//	}
//
//	sort(nums.begin(), nums.end());
//
//	cin >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int num;
//		cin >> num;
//
//		int ans = upper_bound(nums.begin(), nums.end(), num) - lower_bound(nums.begin(), nums.end(), num);
//		cout << ans << ' ';
//	}
//
//}
