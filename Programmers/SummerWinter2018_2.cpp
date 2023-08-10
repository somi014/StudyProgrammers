#include <iostream>
using namespace std;

int solution(int n)
{
	int ans = 0;

	while (n > 0)
	{
		if (0 != (n % 2))		
		{
			n--;
			ans++;
		}
		else
		{
			n = n / 2;
		}
	}
	/*
	주어지는 N / 2로 나누어 떨어지면 순간 이동이 가능하다.
	다시 (N / 2) / 2를 반복해 N이 1이 되면 처음 1칸 이동된 상태가 된다.

	만약, N이 2로 나누어 떨어지지 않으면 마지막에는 점프로 이동해야한다
	N-1을 한 값에서 다시 2로 나누어 떨어지는지 반복한다.
	*/

	return ans;
}

int main()
{
	cout << solution(6) << endl;

	return 0;
}