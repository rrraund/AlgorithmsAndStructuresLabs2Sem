#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<int> vint;
typedef vector<vector<int>> vvint;

const int INF = 1000000000;

struct Edge
{
    int from;
    int to;
    int capacity;
    int flow;
};

vector<Edge> E;
vvint G;
vint ptr;
vint dist;
int n, m, source, sink;


bool bfs()
{
    dist.assign(n, 0);
    queue<int> q;
    q.push(source);
    dist[source] = 1;
    while (!q.empty() && !dist[sink])
    {
        int v = q.front();
        q.pop();
        for (auto &edge : G[v])
        {
            if (!dist[E[edge].to] && E[edge].capacity > E[edge].flow)
            {
                dist[E[edge].to] = dist[v] + 1;
                q.push(E[edge].to);
            }
        }
    }
    return dist[sink];
}


int dfs(int v = source, int flow = INF)
{
    if (flow == 0 || v == sink)
    {
        return flow;
    }

    while (ptr[v] < G[v].size())
    {
        int edge = G[v][ptr[v]];
        if (dist[v] + 1 == dist[E[edge].to])
        {
            int f = dfs(E[edge].to, min(E[edge].capacity - E[edge].flow, flow));
            if (f != 0)
            {
                E[edge].flow += f;
                E[edge ^ 1].flow -= f;
                return f;
            }
        }
        ptr[v]++;
    }
    return 0;
}


void addEdge(int from, int to, int capacity)
{
    G[from].push_back(E.size());
    E.emplace_back(Edge{from, to, capacity, 0});

    G[to].push_back(E.size());
    E.emplace_back(Edge{to, from, 0, 0});
}


void addThreeEdges(int from, int to, int minFlow, int maxFlow)
{
    addEdge(source, to, minFlow);
    addEdge(from, to, maxFlow - minFlow);
    addEdge(from, sink, minFlow);
}



int main()
{
    ios_base::sync_with_stdio(false);
    freopen("circulation.in", "r", stdin);
    freopen("circulation.out", "w", stdout);

    cin >> n >> m;
    n += 2;

    G.resize(n);
    ptr.resize(n, 0);

    source = 0;
    sink = n - 1;
    int from, to, minFlow, maxFlow;

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> minFlow >> maxFlow;
        addThreeEdges(from, to, minFlow, maxFlow);
    }

    while (bfs())
    {
        ptr.assign(G.size(), 0);
        while (dfs()) {}
    }

    for (int edge : G[0])
    {
        if (E[edge].flow < E[edge].capacity)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < E.size(); i += 6)
    {
        cout << E[i + 2].flow + E[i + 4].flow << endl;
    }

    return 0;
}