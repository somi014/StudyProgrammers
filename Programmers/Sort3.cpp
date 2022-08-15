#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(), greater<int>());

	for (int i = 0; i < citations.size(); i++)
	{
		if (citations[i] > i)
			answer++;
		else
			break;
	}

	return answer;
}

int main()
{
	//vector<int> citations = { 3, 0, 6, 1, 5 };	//3
	vector<int> citations = { 1545, 2, 999, 790, 540, 10, 22 };	//6
	//vector<int> citations = { 1, 7, 0, 1, 6, 4 };	//3
	//vector<int> citations = { 10, 50, 100 };		//3
	//vector<int> citations = { 4, 3, 3, 3, 3 };	//3

	solution(citations);

	return 0;
}