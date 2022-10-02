#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool adj[201][201]; //�׷����� ���� ��� ����
vector<bool> visited;

int DFS(int curr, const int n)
{
    if (visited[curr]) 
        return 0;
    visited[curr] = true;

    int ret = 1;
    for (int next = 1; next <= n; next++)
    {
        if (!adj[curr][next]) 
            continue;

        ret += DFS(next, n);
    }
    return ret;
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = 201;

    for (int i = 0; i < wires.size(); i++) //�׷��� �ʱ�ȭ
    {
        int u = wires[i][0];
        int v = wires[i][1];
        adj[u][v] = adj[v][u] = true;
    }

    for (int i = 0; i < wires.size(); i++) //��� ���� �ϳ��� ����� ������ Ž��
    {
        int u = wires[i][0];
        int v = wires[i][1];
        adj[u][v] = adj[v][u] = false; //i��° ���� ����

        vector<int> count;
        visited = vector<bool>(n + 1, false);
        for (int j = 1; j <= n; j++) //��� ������ ���� DFS�� �����Ͽ� 2���� ���� ������ ũ�⸦ ���Ѵ�.
        {
            int temp = DFS(j, n);
            if (!temp) 
                continue;
            count.push_back(temp);
        }
        answer = min(answer, abs(count[0] - count[1])); //���� ����
        adj[u][v] = adj[v][u] = true; //�ٽ� �翬��
    }

    cout << answer << endl;
    return answer;
}

int main()
{
    vector<vector<int>> wires = { {1,3}, {2,3}, {3,4},{4,5},{4,6},{4,7},{7,8},{7,9}};
    solution(9, wires);

    return  0;
}