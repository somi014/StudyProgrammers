#include <string>
#include <vector>
#include <iostream>

/// <summary>
/// 프로그래머스 c++ 2레벨 피보나치 수
/// </summary>
using namespace std;

int solution(int n) {
    int answer = 0;
    int num = 1234567;

    int a = 0;
    int b = 1;

    for (int i = 2; i <= n; i++)
    {
        answer = ((a % num) + (b % num)) % num;
        a = b;
        b = answer;
    }

    return answer;
}

int main()
{
    int n = 5;
    cout << solution(n) << endl;

    return 0;
}