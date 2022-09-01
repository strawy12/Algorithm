#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
vector<int> solution(vector<string> id_list, vector<string> reports, int k);

int main()
{
	vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
	vector<string> reports = { "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" };
	
	auto v = solution(id_list, reports, 2);

	for (auto s : v)
	{
		cout << s << " ";
	}
}


vector<int> solution(vector<string> id_list, vector<string> reports, int k) {
	int size = id_list.size();

	map<string, int> id_idx;
	vector<int> reportedCnt(size, 0);
	vector<int> answer(size, 0);
	vector<vector<string>> reporters(size);

	for (int i = 0; i < id_list.size(); i++)
	{
		id_idx.insert({ id_list[i],i });
	}

	reports.erase(unique(reports.begin(), reports.end()), reports.end());

	for (string report : reports)
	{
		int nPos = report.find(" ");
		string reporter = report.substr(0, nPos);
		string reported = report.substr(nPos + 1, report.length() - nPos);

		int idx = id_idx[reported];

		bool isBoth = false;
		for (auto r : reporters[idx])
		{
			if (reporter == r)
			{
				isBoth = true;
				
				break;
			}
		}

		if (!isBoth)
		{
			reporters[idx].push_back(reporter);
			reportedCnt[idx]++;
		}
	}

	for (int i = 0; i < reportedCnt.size(); i++)
	{
		if (reportedCnt[i] >= k)
		{
			for (int j = 0; j < reporters[i].size(); j++)
			{
				int idx = id_idx[reporters[i][j]];
				answer[idx]++;
			}
		}
	}


	return answer;
}