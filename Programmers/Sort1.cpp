//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//	vector<int> answer;
//
//	vector<int> list;
//
//	for (int i = 0; i < commands.size(); i++)
//	{
//		list.clear();
//		for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
//		{
//			list.push_back(array[j]);
//		}
//		sort(list.begin(), list.end());
//		answer.push_back(list.at(commands[i][2] - 1));
//	}
//
//	return answer;
//}