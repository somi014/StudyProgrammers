#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) 
{
	vector<int> answer(prices.size());
	stack<int> s;
	int size = prices.size();

	for (int i = 0; i < size; i++) 
	{
		if(!s.empty())
		while (!s.empty() && prices[s.top()] > prices[i]) 
		{
			answer[s.top()] = i - s.top();
			s.pop();
		}
		s.push(i); 
	}
	while (!s.empty()) 
	{
		answer[s.top()] = size - s.top() - 1;
		s.pop();
	}
	return answer;
}

int main()
{
	vector<int> vec = { 1, 2, 3, 2, 3 };
	vector<int> answer;
	answer = solution(vec);
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}

	return 0;
}