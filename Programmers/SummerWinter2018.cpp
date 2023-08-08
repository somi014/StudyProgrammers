#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool Compare(char a, char b)
{
	if (a == b)
	{
		return true;
	}
	return false;
}

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;

	bool stop = false;
	for (int i = 1; i < words.size(); i++)
	{
		stop = false;
		bool same = Compare(words[i - 1].back(), words[i].front());
		if (same == false)
		{
			stop = true;
			cout << "worng start " << i << endl;
		}

		for (int j = 0; j < i; j++)
		{
			if (words[j] == words[i])
			{
				stop = true;
			cout << "same " << i << endl;
			}
		}

		if (stop == true)
		{
			answer.push_back((i % n) + 1);
			answer.push_back((i / n) + 1 );
			break;
		}
	}
	if (answer.size() < 1)
	{
		answer = { 0, 0 };
	}
	return answer;
}


int main()
{

	//vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
	vector<string> words = { "hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive" };
	//vector<string> words = { "hello", "one", "even", "never", "now", "world", "draw" };

	vector<int> answer = solution(5, words);
	cout << "result : " << answer[0] << ", " << answer[1] << endl;

	return 0;
}