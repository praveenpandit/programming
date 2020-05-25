#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void display(vector<vector<int>> gp)
{
    cout << gp.size() << endl;
    for (int i = 1; i < gp.size(); i++)
    {
        cout << i << "=";
        for (auto j : gp[i])
            cout << j << "->";
        cout << endl;
    }
}
int bfs(vector<vector<int>> gp)
{
    if (gp.empty())
        return -1;
    int len = gp.size();
    queue<int> q;
    bool visited[10][2] = {
        false,
    };
    q.push(1);
    visited[1][0] = true;
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (auto i : gp[k])
        {
            if (!visited[i][0])
            {
                visited[i][0] = true;
                q.push(i);
            }
        }
    }
    for (auto i = 1; i < gp.size(); i++)
    {
        cout << visited[i][0] << " " << visited[i][1] << endl;
    }
}
int main()
{
    vector<vector<int>> graph = {{},
                                 {3, 4, 7, 9},
                                 {3, 8},
                                 {1, 2},
                                 {1},
                                 {6},
                                 {5},
                                 {1},
                                 {2, 9},
                                 {1, 8}};
    display(graph);
    bfs(graph);
    return 0;
}