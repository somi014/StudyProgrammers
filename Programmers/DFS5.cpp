#include <string>
#include <vector>

using namespace std;

bool visited[100][100];

void dfs(int count, vector<vector<int>> wires){

    for (int i = 0; i < wires.size(); ++i) {
        for (int j = 0; j < wires[i].size(); ++j) {
            if(visited[i][j] == false)
            {
                dfs(count++, wires)
            }
        }

    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;

    for (int i = 0; i < wires.size(); ++i) {
        for (int j = 0; j < wires[i].size(); ++j) {
            visited[i][j] = visited[j][i] = false;
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> wires = { {1,3}, {2,3}, {3,4},{4,5},{4,6},{4,7},{7,8},{7,9}};
    solution(9, wires);

    return  0;
}