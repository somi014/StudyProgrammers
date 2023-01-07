#include <string>
#include <vector>
#include <iostream>

using namespace std;

/// <summary>
/// 프로그래머스 c++ 2레벨 숫자의 표현
/// </summary>

int solution(int n) {
    int answer = 0;

    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum = i;
        for (int j = i + 1; j < n; j++)
        {
            sum += j;

            if (sum == n)
            {
                answer++;
                break;
            }
            else if (sum > n)
            {
                break;
            }
        }
    }

    return answer + 1;
}

int main()
{
    int n = 12;
    
    cout << "solution " << solution(n) << endl;


    return 0;
}