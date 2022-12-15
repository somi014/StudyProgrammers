#include <string>
#include <vector>
#include <iostream>
#include <algorithm>		//프로그래머스에서 없으니까 에러남
using namespace std;

string change(int num);

vector<int> solution(string s) {
	vector<int> answer;
	answer.push_back(-1);
	answer.push_back(0);

	int origin_size = s.size();
	while (origin_size > 1)
	{
		origin_size = s.size();
		s.erase(remove(s.begin(), s.end(), '0'), s.end());
		
		answer[0]++;
		answer[1] += origin_size - s.size();

		s = change(s.size());
	}


	return answer;
}

string change(int num)
{
	string result;
	while (num > 1)
	{
		result += to_string(num % 2);
		num = num / 2;
	}
	result += "1";

	return result;
}

int main()
{
	//string s = "110010101001";
	//string s = "01110";
	//string s = "1111111";
	string s = "0000100";


	solution(s);

	return 0;
}