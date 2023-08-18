#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 0;

    sort(arr.begin(), arr.end());

    int start = arr[0];
    int result = 0;
    for (int i = 1; i < arr.size(); i++)
    {        
        result = lcm(start, arr[i]);            //두수의 최소 공배수와 다음 수와 비교
        start = result;
    }

    return start;
}

int main()
{
    //vector<int> arr = { 2,6,8,14 };
    vector<int> arr = { 1,2,3 };
    cout << solution(arr) << endl;

    return 0;
}