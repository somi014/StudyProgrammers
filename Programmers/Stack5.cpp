#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++)
    {
        int temp = arr[i];
        if (answer.size() < 1)
        {
            answer.push_back(temp);
        }

        if (answer.back() != temp)
        {
            answer.push_back(temp);
        }
    }
    return answer;
}

int main()
{
    //vector<int> arr = { 1,1,3,3,0,1,1 };
    vector<int> arr = { 4,4,4,3,3 };
    vector<int> answer = solution(arr);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}