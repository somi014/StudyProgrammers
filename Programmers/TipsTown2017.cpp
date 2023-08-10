#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    int abs_num = 0;
    bool stop = false;

    while (stop == false)
    {
        a = (a / 2) + (a % 2);          // 1과 2번이 붙었을 때 이긴사람은 1이 되도록 만든다
        b = (b / 2) + (b % 2);

        abs_num = abs(a - b);           //a와 b가 일련의 숫자가 되었을 때 맞붙을 수 있다
        if (abs_num == 0)
        {
            stop = true;
        }
        answer++;
    }

    return answer;
}


int main()
{
    cout << solution(8, 4, 7) << endl;

    return 0;
}