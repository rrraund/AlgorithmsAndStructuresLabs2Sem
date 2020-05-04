#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = 1000000000;

typedef vector<int> vint;
typedef vector<vector<int>> vvint;


bool bfs(vvint &matrix, int source, int sink, vint &parent)
{
    int n = matrix.size();
    vector<bool> mark(n);
    queue <int> q;
    q.push(source);
    mark[source] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (!mark[i] && matrix[v][i] > 0)
            {
                parent[i] = v;
                mark[i] = true;
                q.push(i);
            }
        }
    }
    return mark[sink];
}


//EdmondsKarp
int maxFlow(vvint &matrix, int source, int sink, vint &parent)
{
    int maxFlow = 0;
    while (bfs(matrix, source, sink, parent))
    {
        int flow = inf;
        for (int cur = sink; cur != source; cur = parent[cur])
        {
            int prev = parent[cur];
            flow = min(matrix[prev][cur], flow);
        }
        for (int cur = sink; cur != source; cur = parent[cur])
        {
            int prev = parent[cur];
            matrix[cur][prev] += flow;
            matrix[prev][cur] -= flow;
        }
        maxFlow += flow;
    }
    return maxFlow;
}



int main()
{
    ios_base::sync_with_stdio(false);
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);

    int n, m, a, b, w;
    cin >> n >> m;

    vvint matrix(n, vint(n, 0));
    vint parent(n, -1);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        a--;
        b--;
        matrix[a][b] = w;
    }

    cout << maxFlow(matrix, 0, n - 1, parent);

    return 0;
}