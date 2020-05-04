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
    int number;
};

vector<Edge> E;
vvint G;
vvint answer;
vint ptr;
vint dist;
int n, m, source, sink;


void addEdge(int from, int to, int capacity, int number)
{
    G[from].push_back(E.size());
    E.emplace_back(Edge{from, to, capacity, 0, number});

    G[to].push_back(E.size());
    E.emplace_back(Edge{to, from, 0, 0, number});
}


bool bfs()
{
    dist.assign(n, 0);
    queue<int> q;
    q.push(source);
    dist[source] = 1;
    while (!q.empty() && !dist[sink])
    {
        int from = q.front();
        q.pop();
        for (auto &edge : G[from])
        {
            if (!dist[E[edge].to] && E[edge].capacity > E[edge].flow)
            {
                q.push(E[edge].to);
                dist[E[edge].to] = dist[from] + 1;
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


int decomposition(int v, int minFlow = INF)
{
    if (v == sink)
    {
        answer.emplace_back();
        return minFlow;
    }

    for (int edge : G[v])
    {
        if (E[edge].flow > 0)
        {
            int result = decomposition(E[edge].to, min(minFlow, E[edge].flow));
            if (result != 0)
            {
                answer.back().push_back(E[edge].number);
                if (v == source)
                {
                    answer.back().push_back(answer[answer.size() - 1].size());
                    answer.back().push_back(result);
                    reverse(answer.back().begin(), answer.back().end());
                }
                E[edge].flow -= result;
                return result;
            }
        }
    }
    return 0;
}



int main()
{
    ios_base::sync_with_stdio(false);
    freopen("decomposition.in", "r", stdin);
    freopen("decomposition.out", "w", stdout);

    cin >> n >> m;

    G.resize(n);
    ptr.resize(n, 0);

    source = 0;
    sink = n - 1;
    int from, to, capacity;

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> capacity;
        from--;
        to--;

        addEdge(from, to, capacity, i + 1);
    }

    while (bfs())
    {
        ptr.assign(n, 0);
        while (dfs()) {}
    }

    while (decomposition(source)) {}

    cout << answer.size() << endl;
    for (auto &i : answer)
    {
        for (auto &j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}