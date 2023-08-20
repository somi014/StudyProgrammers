#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> row;
        for (int j = 0; j < arr2[0].size(); j++)
        {
            int row_tmp = 0;
            for (int n = 0; n < arr1[i].size(); n++)
            {
                row_tmp += arr1[i][n] * arr2[n][j];
            }
            row.push_back(row_tmp);
        }
        answer.push_back(row);
    }

    return answer;
}