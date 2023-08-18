#include <string>
#include <vector>
#include <iostream>

using namespace std;

//시간 초과
void DFS(long long total, int n, long long &count)
{
	if (total > n)
	{
		return;
	}

	if (total == n)
	{
		count++;
		return;
	}

	DFS(total + 1, n, count);
	DFS(total + 2, n, count);
}

int dp[2001];

long long solution(int n) {
	long long answer = 0;

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;			
	}
	answer = dp[n];

	return answer;
}


int main()
{
	int n = 1999;
	cout << solution(n) << endl;

	return 0;
}