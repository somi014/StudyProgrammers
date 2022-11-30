#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;

	map<int, int> type;

	for (int i = 0; i < nums.size(); i++)
	{
		type[nums[i]]++;
	}

	for (int i = 0; i < type.size(); i++)
	{
		answer++;
		if (answer >= nums.size() / 2)
		{
			break;
		}
	}

	cout << "answer1  : " << answer << endl;

	return answer;
}

int main()
{
	//vector<int> nums = { 3,1,2,3 };
	vector<int> nums = { 3,3,3,2,2,4 };
	//vector<int> nums = { 3,3,3,2,2,2 };
	//vector<int> nums = { 1,2,3,4,5,2 };
	solution(nums);
}