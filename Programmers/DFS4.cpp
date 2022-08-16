#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> check(8, 0);
vector<int> countList;
void dfs(int k, vector<vector<int>> dungeons, int index, int count, int& answer)
{
	if (count > answer)
	{
		answer = count;
	}

	for (int i = 0; i < dungeons.size(); i++)
	{
		if (check[i] == 0 && dungeons[i][0] <= k)
		{
			check[i] = 1;
			dfs(k - dungeons[i][1], dungeons, index + 1, count + 1, answer);
			check[i] = 0;
		}
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	int answer = -1;

	dfs(k, dungeons, 0, 0, answer);

	//sort(countList.rbegin(), countList.rend());
	//answer = countList[0];
	//for (int i = 0; i < countList.size(); ++i) {
	//	cout << "i : " << countList[i] << endl;
	//}
	cout << answer << endl;
	return answer;
}

int main()
{
	vector<vector<int>> dungeons = { {80,20},{50,40},{30,10} };
	solution(80, dungeons);

	return 0;
}