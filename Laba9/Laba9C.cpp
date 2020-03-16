#include <iostream>
#include <vector>

using namespace std;

bool DFS1(vector<vector <int> > &list, vector<int> &mark, int v);
bool DFS2(vector<vector <int> > &list, vector<int> &mark, int v);

bool DFS1(vector<vector <int> > &list, vector<int> &mark, int v)
{
    mark[v] = 1;
    for (int i = 0; i < list[v].size(); i++)
    {
        if (mark[list[v][i]] == 0)
        {
            if (DFS2(list, mark, list[v][i]))
            {
                return true;
            }
        }
        if (mark[list[v][i]] == 1)
        {
            return true;
        }
    }
    return false;
}

bool DFS2(vector<vector <int> > &list, vector<int> &mark, int v)
{
    mark[v] = 2;
    for (int i = 0; i < list[v].size(); i++)
    {
        if (mark[list[v][i]] == 0)
        {
            if (DFS1(list, mark, list[v][i]))
            {
                return true;
            }
        }
        if (mark[list[v][i]] == 2)
        {
            return true;
        }
    }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false);

    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int> > list(n, vector<int>());
    vector<int> mark(n, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 0)
        {
            if (DFS1(list, mark, i))
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}