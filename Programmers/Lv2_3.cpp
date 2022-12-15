#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    return a > b;       //내림차순
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), compare);

    for (int i = 0; i < A.size(); i++)
    {
        answer += (A[i] * B[i]);
    }
    cout << answer << endl;

    return answer;
}

int main()
{
    //vector<int> A = { 1, 4, 2 };
    //vector<int> B = { 5, 4, 4 };
    vector<int> A = { 1, 2 };
    vector<int> B = { 3, 4 };

    solution(A, B);

    return 0;
}