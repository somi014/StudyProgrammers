#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool Compare(string a, string b)
{
	int temp = a + b > b + a;
	cout << (a + b > b + a) << endl;
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> num;

	for (int i = 0; i < numbers.size(); i++)
	{
		num.push_back(to_string(numbers[i]));
	}
	sort(num.begin(), num.end(), Compare);
	
	for (int i = 0; i < num.size(); i++)
	{
		answer += num[i];
	}
	if (answer[0] == '0') answer = "0";


	return answer;
}

int main()
{
	cout << solution({ 6, 10, 2 }) << endl;
	return 0;
}