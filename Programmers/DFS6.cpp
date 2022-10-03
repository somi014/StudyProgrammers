#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
	int answer = 0;

	int minW = 0;
	int minH = 0;
	for (int i = 0; i < sizes.size(); ++i) {
		if (minW > sizes[i][0]) {
			minW = sizes[i][0];
		}
		if (minH > sizes[i][1]) {
			minH = sizes[i][1];
		}
	}

	int size1 = 0;
	int size2 = 0;

	for (int i = 0; i < sizes.size(); i++)
	{
		int tempW = minW;
		int tempH = minH;
		int tempW2 = minW;
		int tempH2 = minH;
		if (minW < sizes[i][0])
		{
			tempW = sizes[i][0];
		}
		if (minH < sizes[i][1])
		{
			tempH = sizes[i][1];
		}
		size1 = tempW * tempH;

		if (minW < sizes[i][1])
		{
			tempW2 = sizes[i][1];
		}
		if (minH < sizes[i][0])
		{
			tempH2 = sizes[i][0];
		}
		size2 = tempW2 * tempH2;

		if (size1 <= size2)
		{
			minW = tempW;
			minH = tempH;
		}
		else
		{
			minW = tempW2;
			minH = tempH2;
		}
	}

	answer = minW * minH;
	return answer;
}

int main()
{
	//vector<vector<int>> sizes = { {60, 50}, {30, 70}, {60, 30,}, { 80, 40} };
	vector<vector<int>> sizes = { {10, 7 }, { 12, 3 }, { 8, 15 }, { 14, 7 }, { 5, 15 } };
	solution(sizes);

	return 0;
}
