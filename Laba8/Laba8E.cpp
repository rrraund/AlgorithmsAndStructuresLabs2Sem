#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector <int> > &list, vector<bool> &mark, vector<int> &d)
{
    queue<int> q;
    q.push(1);
    d[1] = 0;
    mark[1] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < list[v].size(); i++)
        {
            if (mark[list[v][i]] == 0)
            {
                d[list[v][i]] = d[v] + 1;
                mark[list[v][i]] = 1;
                q.push(list[v][i]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("pathbge1.in", "r", stdin);
    freopen("pathbge1.out", "w", stdout);

    int n, m, a ,b;
    cin >> n >> m;
    vector<vector <int> > list(n + 1,vector<int>());
    vector<bool> mark(n + 1);
    vector<int> distance(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (a == b)
        {
            list[a].push_back(b);
        }
        else
        {
            list[a].push_back(b);
            list[b].push_back(a);
        }
    }

    BFS(list, mark, distance);
    for (int i = 1; i <= n; i++)
    {
        cout << distance[i] << ' ';
    }
    return 0;
}