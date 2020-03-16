#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool DFS(vector<vector <int> > &list, vector<int> &mark, int v, stack<int> &topSort)
{
    mark[v] = 1;
    for (int i = 0; i < list[v].size(); i++)
    {
        if (mark[list[v][i]] == 0)
        {
            if (!DFS(list, mark, list[v][i], topSort))
            {
                return false;
            }
        }
        if (mark[list[v][i]] == 1)
        {
            return false;
        }
    }
    topSort.push(v);
    mark[v] = 2;
    return true;
}


int main()
{
    ios_base::sync_with_stdio(false);
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int> > list(n, vector<int>());
    vector<int> mark(n, 0);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        list[--a].push_back(--b);
    }

    stack<int> topSort;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 0)
        {
            if (!DFS(list, mark, i, topSort))
            {
                cout << "-1";
                return 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << topSort.top() + 1 << " ";
        topSort.pop();
    }
    return 0;
}