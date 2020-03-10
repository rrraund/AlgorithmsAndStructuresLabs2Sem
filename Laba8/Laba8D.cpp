#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector <int> > &list, vector<bool> &mark, vector <int> &component, int v, int count)
{
    mark[v] = 1;
    component[v] = count;
    for (int i = 0; i < list[v].size(); i++)
    {
        if (mark[list[v][i]] == 0)
        {
            DFS(list, mark, component, list[v][i], count);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);

    int n, m, a ,b, count;
    count = 0;
    cin >> n >> m;
    vector<vector <int> > list(n + 1,vector<int>());
    vector<bool> mark(n + 1);
    vector<int> component(n + 1, -1);

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

    for (int i = 1; i <= n; i++)
    {
        if (mark[i] == 0)
        {
            count++;
            DFS(list, mark, component, i, count);
        }
    }

    cout << count << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << component[i] << ' ';
    }
    return 0;
}