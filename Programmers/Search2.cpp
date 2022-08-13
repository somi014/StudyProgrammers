#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <math.h>
#include <algorithm>
using namespace std;

bool Sosu(int a);

int solution(string numbers) {
    int answer = 0;

	vector<char> num;
	unordered_map<int, bool> combine;
	for (int i = 0; i < numbers.length(); i++)
	{
		num.push_back(numbers[i]);
	}
	sort(num.begin(), num.end());
	do {
		string temp = "";
		for (int i = 0; i < num.size(); i++) 
		{
			temp.push_back(num[i]);			//1, 12, 123 ...
			combine.insert(make_pair(stoi(temp), Sosu(stoi(temp))));
		}

	} while (next_permutation(num.begin(), num.end()));

	for(auto com : combine)
	{
			cout << com.first << endl;
		if (com.second == true)
		{
			answer++;
		}
	}
	cout << answer << endl;
    return answer;
}

bool Sosu(int n)
{	
	if (n < 2) return false; // 에라토스테네스의 체 
	for (int i = 2; i <= sqrt(n); i++) 
		if (n % i == 0) return false; 
	return true;
}

int main()
{
	solution("17");

	return 0;
}

