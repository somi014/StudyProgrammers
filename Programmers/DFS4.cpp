#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> countList;
void dfs(int k, vector<vector<int>> dungeons, int count)
{
    if(dungeons.size() == 0)
    {
        countList.push_back(count);
        cout << "size 0 " << count << endl;
        cout << endl;
        return;
    }

    for (int i = 0; i < dungeons.size(); i++)
    {
        cout << "========="<< endl;
        if(dungeons[i][0] <= k)
        {
            cout << "limit " << dungeons[i][0] << endl;
            cout << "cur " << k << endl;
            dungeons.erase(dungeons.begin() + i);
            k -= dungeons[i][1];
            cout << "left " << k << endl;
            dfs(k, dungeons, ++count);
        }
    }

    cout <<"out " << count << endl;
    cout << endl;
    countList.push_back(count);
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    sort(dungeons.rbegin(), dungeons.rend());
    for (int i = 0; i < dungeons.size(); i++) {
        dfs(k, dungeons, 0);
    }

    sort(countList.rbegin(), countList.rend());
    answer = countList[0];
    for (int i = 0; i < countList.size(); ++i) {
        cout << "i : " << countList[i] << endl;
    }
    cout << answer  << endl;
    return answer;
}

int main()
{
    vector<vector<int>> dungeons = {{80,20},{50,40},{30,10}};
    solution(80, dungeons);

    return 0;
}