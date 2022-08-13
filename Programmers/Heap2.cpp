#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		return a.at(1) > b.at(1);
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0, j = 0, time = 0;
	sort(jobs.begin(), jobs.end());
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	while (j < jobs.size() || !pq.empty()) {
		if (jobs.size() > j && time >= jobs[j][0]) {
			pq.push(jobs[j++]);
			continue;
		}
		if (!pq.empty()) {
			time += pq.top()[1];
			answer += time - pq.top()[0];
			cout << "0 : " << pq.top()[0] << endl;
			cout << "1 : " << pq.top()[1] << endl;
			pq.pop();
		}
		else
			time = jobs[j][0];
	}
	return answer / jobs.size();
}

void print(vector<vector<int>> jobs, int answer) {
	int t = solution(jobs);
	if (t == answer)
		cout << "정답" << endl;
	else
		cout << "틀림" << endl;
}

int main() {
	print({ {0, 3}, {1, 9}, {2, 6} }, 9);
	print({ {0, 9}, {0, 4}, {0, 5}, {0, 7}, {0, 3} }, 13);
	print({ {1, 9}, {1, 4}, {1, 5}, {1, 7}, {1, 3} }, 13);
	print({ {0, 3}, {4, 4}, {5, 3}, {4, 1} }, 3);
	print({ {0, 3}, {1, 9}, {500, 6} }, 6);
	return 0;
}