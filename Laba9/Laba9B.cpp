#include <iostream>
#include <vector>

using namespace std;

vector<int> DFS(vector<vector <int> > &list, vector<int> &mark, int v)
{
    mark[v] = 1;
    for (int i = 0; i < list[v].size(); i++)
    {
        if (mark[list[v][i]] == 0)
        {
            vector<int> cycle = DFS(list, mark, list[v][i]);
            if (!cycle.empty())
            {
                if (cycle.front() != cycle.back() || cycle.size() == 1)
                {
                    cycle.push_back(v);
                }
                return cycle;
            }
        }
        if (mark[list[v][i]] == 1)
        {
            return {list[v][i], v};
        }
    }
    mark[v] = 2;
    return {};
}


int main()
{
    ios_base::sync_with_stdio(false);
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int> > list(n, vector<int>());
    vector<int> mark(n, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        list[--a].push_back(--b);
    }

    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 0)
        {
            vector<int> cycle = DFS(list, mark, i);
            if (!cycle.empty())
            {
                cout << "YES" << endl;
                for (int j = cycle.size() - 1; j > 0; j--)
                {
                    cout << cycle[j] + 1 << ' ';
                }
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}