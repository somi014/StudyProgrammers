#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> FuncFind(int _num)
{
	vector<int> arr;

	for (int i = 1; i <= sqrt(_num); i++)
	{
		if (_num % i == 0)
		{
			arr.push_back(i);				
			arr.push_back(_num / i);			
		}
	}
	sort(arr.begin(), arr.end());

	vector<int> result;
	int index = arr.size() / 2;
	result.push_back(arr[index]);
	result.push_back(arr[index - 1]); 

	return arr;
}

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	vector<int> result;

	int total = brown + yellow;
	result = FuncFind(total);

	bool stop = false;
	int index = 0;

	while (stop == false)
	{
		index = result.size() / 2;
		if ((result[index] - 2) * (result[index - 1] - 2) != yellow)
		{
			cout << "erase " << result[index] << endl;
			result.erase(result.begin() + index);
			cout << "erase " << result[index - 1] << endl;
			result.erase(result.begin() + index - 1); 
		}
		else
		{
			stop = true;
			answer.push_back(result[index]);
			answer.push_back(result[index - 1]);
			break;
		}
	}

		
	return answer;
}

int main(void)
{
	int B;
	cin >> B;
	int Y;
	cin >> Y;


	//FuncFind(N);
	vector<int> answer= solution(B, Y);

	for (int i = 0; i < 2; i++)
	{
		cout << answer[i] << endl;
	}
	

	return 0;
}