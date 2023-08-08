#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;

	sort(people.begin(), people.end());

	int left = 0;									//남은 사람
	int alone = 0;									//혼자 타는 사람

	int big = people.size() - 1;					//남은 사람 중 가장 무거운 사람

	while (left < big)
	{
		if (people[left] + people[big] <= limit)
		{
			left++;									//다음으로 가벼운 사람
		}

		answer++;
		big--;
	}
	
	if (left == big)				//남은 사람 == 다음으로 무거운 사람 => 혼자 남은 사람
	{
		answer++;
	}

	return answer;
}

int main()
{
	vector<int> people = { 70, 50, 80, 50 };
	//vector<int> people = { 70, 80, 50 };
	//vector<int> people = { 40, 40, 40, 40, 50 };
	//vector<int> people = { 60, 60, 51, 51, 100 };
	//vector<int> people = { 40 };
	//vector<int> people = { 40, 55, 55, 60, 60, 60, 70, 80 };


	int limit = 100;
	cout << solution(people, limit) << endl;

	return 0;
}