#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
	int answer = 0;

	sort(jobs.begin(), jobs.end());
	multimap<int, int, greater<int>> wait;

	int index = 0;
	int time = 0;			//경과 시간
	int count = 0;
	int d = 0;
	int t = 0;
	while (jobs.size() > count || !wait.empty())
	{
		if (wait.size() == 0)
		{
			wait.insert(make_pair(jobs[index][0], jobs[index][1]));

			d = wait.begin()->first;
			t = wait.begin()->second;
			time += t;
			cout << "d " << d << " / t " << t << " / time " << time << endl;
			wait.erase(wait.begin());
			answer += t;
			cout << "anwser " << answer << endl;
			for (int i = index + 1; i < jobs.size(); i++)
			{
				index++;
				if (jobs[index][0] <= time)
				{
					wait.insert(make_pair(jobs[index][0], jobs[index][1]));
					cout << "insert " << jobs[index][0] << " / " << jobs[index][1] << endl;
				}
			}
		}
		else
		{
			d = wait.begin()->first;
			t = wait.begin()->second;
			time += t;
			cout << "d1 " << d << " / t1 " << t << " / time " << time << endl;

			wait.erase(wait.begin());
			answer += (time - d);
			cout << "anwser " << answer << endl;
		}
		count++;
	}


	return answer / jobs.size();
}

int main()
{
	//vector<vector<int>> jobs = { {0, 3}, { 1, 9 }, { 2, 6 } };
	//vector<vector<int>> jobs = { {0, 9}, {0, 4}, {0, 5}, {0, 7}, {0, 3} };
	//vector<vector<int>> jobs = { {0, 3}, {1, 9}, {500, 6} };
	vector<vector<int>> jobs = { {1, 9}, {1, 4}, {1, 5}, {1, 7}, {1, 3} };
	cout << solution(jobs) << endl;

	return 0;
}