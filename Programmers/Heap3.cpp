#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;

	vector<pair<string, int>> oper;
	for (int i = 0; i < operations.size(); i++)
	{
		string s1 = operations[i].substr(0, 1);
		int s2 = stoi(operations[i].substr(2, operations[i].size()));

		oper.push_back(make_pair(s1, s2));
	}

	deque<int> pq;
	for (int i = 0; i < oper.size(); i++)
	{
		if (oper[i].first == "I")
		{
			pq.push_back(oper[i].second);
			sort(pq.begin(), pq.end());
		}
		else
		{
			if (pq.empty() == true)
			{
				continue;
			}

			if (oper[i].second > 0)
			{
				pq.pop_back();
			}
			else
			{
				pq.pop_front();
			}
		}
	}

	if (pq.size() > 0)
	{
		answer.push_back(pq.back());
		answer.push_back(pq.front());
	}
	else
	{
		answer.push_back(0);
		answer.push_back(0);
	}

	return answer;
}

vector<int> solution2(vector<string> arguments) {
	vector<int> answer;
	multiset<int> que;
	multiset<int>::iterator iter;
	string sub;

	for (auto s : arguments) {
		sub = s.substr(0, 2);
		if (sub == "I ") que.insert(stoi(s.substr(2, s.length() - 2)));
		else if (s.substr(2, 1) == "1" && que.size() > 0) { que.erase(--que.end()); }
		else if (que.size() > 0) { que.erase(que.begin()); }
	}

	if (que.size() == 0) { answer.push_back(0); answer.push_back(0); }
	else {
		iter = --que.end(); answer.push_back(*iter);
		iter = que.begin(); answer.push_back(*iter);
	}

	return answer;
}


int main()
{
	vector<string> operations = { "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" };
	//vector<string> operations = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };
	//vector<string> operations = { "I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6" };
	//vector<string> operations = { "I 4", "I -1", "I 6", "I 3" };
	solution2(operations);


	return 0;
}