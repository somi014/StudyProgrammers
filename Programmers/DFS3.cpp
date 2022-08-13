//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//bool Check(string a, string b);
//vector<int> result;
//
//void dfs(string begin, string target, vector<string> words, int answer, int n = 0)
//{
//	if (words.size() == 0)
//	{
//		return;
//	}
//
//	if (begin == target)
//	{
//		result.push_back(answer);
//		cout << "=====" << answer << "======" << endl;
//		return;
//	}
//
//	int count;
//
//	for (int i = 0; i < words.size(); i++)
//	{
//		count = answer;
//		if (Check(begin, words[i]))
//		{
//			vector<string> temp = words;
//			count++;
//			temp.erase(temp.begin() + i);
//			dfs(words[i], target, temp, count, i + 1);
//		}
//	}		
//}
//
//
//bool Check(string a, string b)
//{
//	int count = 0;
//	for (int i = 0; i < a.size(); i++)
//	{
//		if (a[i] != b[i])
//			count++;
//	}
//
//	if (count == 1)
//	{
//		cout << a << " & " << b << " : true" << endl;
//		return true;
//	}
//	else
//	{
//		cout << a << " & " << b << " : false" << endl;
//		return false;
//	}
//}
//
//int solution(string begin, string target, vector<string> words) {
//	int answer = 0;
//
//	int min = 0;
//	for (int i = 0; i < words.size(); i++)
//	{
//		if (words[i] == begin)
//		{
//			words.erase(words.begin() + i);
//			cout << "same" << endl;
//		}
//	}
//
//	dfs(begin, target, words, answer);
//	
//	if (result.size() != 0)
//	{
//		answer = result[0];
//		for (int i = 1; i < result.size(); i++)
//		{
//			if (answer > result[i])
//			{
//				answer = result[i];
//			}
//		}
//	}
//
//	cout << answer << endl;
//	return answer;
//}
//
//int main()
//{
//	//vector<string> words = vector<string>({ "hot", "dot", "dog", "lot", "log", "cog" });
//	vector<string> words = vector<string>({ "hot", "dot", "dog", "lot", "log" });
//	solution("hit", "cog", words);
//
//
//	return 0;
//}
