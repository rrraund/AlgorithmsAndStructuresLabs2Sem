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
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);

    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int> > list(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        list[--a].push_back(--b);
    }

    vector<int> mark(n, 0);
    stack<int> topSort;

    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 0)
        {
            DFS(list, mark, i, topSort);
        }
    }

    bool flag = true;
    int prev, next;
    int size = topSort.size();

    for (int i = 0; i < size - 1; i++)
    {
        prev = topSort.top();
        topSort.pop();
        next = topSort.top();
        flag = false;
        for (int j = 0; j < list[prev].size(); j++)
        {
            if (list[prev][j] == next)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            break;
        }
    }

    if (flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}