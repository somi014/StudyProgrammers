#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    int row = 0;
    int col = 0;
    for (int i = left; i <= right; i++) {
       row = i / n;
       col = i % n;
       if(row >= col) {
           answer.push_back(row + 1);
       }
       else {
           answer.push_back(col + 1);
       }
    }
    return answer;
}

int main()
{
    solution(3, 2, 5);
    return 0;
}