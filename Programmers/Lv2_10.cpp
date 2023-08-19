#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    map<int, int> tanCount;
    for (int i = 0; i < tangerine.size(); ++i) {
        tanCount[tangerine[i]]++;
    }

    vector<int> count;
    for (auto it = tanCount.begin(); it != tanCount.end(); it++)
    {
        count.push_back((*it).second);
    }

    sort(count.begin(), count.end(), greater<int>());
    int total = 0;
    for (int i = 0; i < count.size(); ++i) {

        if(total >= k)
        {
            break;
        }
        total += count[i];
        answer ++;
    }

    return answer;
}

int main()
{
    vector<int> tangerine = {1, 3, 2, 5, 4, 5, 2, 3};

    cout<< solution(6, tangerine)<< endl;

    return 0;
}