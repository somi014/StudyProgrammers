#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

	vector<int> a = { 1, 2, 3, 4, 5 };
	vector<int> b = { 2, 1, 2, 3, 2, 4, 2, 5 };
	vector<int> c = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	vector<int> q_count(3);
	
	for (int i =0; i < answers.size(); i++)
	{
		if (answers[i] == a[i % 5])
			q_count[0]++;
		if(answers[i] == b[i % 8])
			q_count[1]++;
		if(answers[i] == c[i % 10])
			q_count[2]++;
	
	}
	int maxScore = 0;
	maxScore = max(max(q_count[0], q_count[1]), q_count[2]);
	for (int i = 0; i < 3; i++)
	{
		if (q_count[i] == maxScore)
			answer.push_back(i + 1);
	}
}

int max(int a, int b) {
	return a < b ? b : a;
}
