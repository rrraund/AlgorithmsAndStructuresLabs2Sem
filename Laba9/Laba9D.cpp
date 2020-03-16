#include <iostream>
#include <vector>

using namespace std;

void DFS1(vector<vector <int> > &list, vector<bool> &mark, int v, vector<int> &topSort)
{
    mark[v] = 1;
    for (int i = 0; i < list[v].size(); i++)
    {
        if (mark[list[v][i]] == 0)
        {
            DFS1(list, mark, list[v][i], topSort);
        }
    }
    topSort.push_back(v);
}

void DFS2(vector<vector <int> > &list, vector<bool> &mark, vector <int> &components, int v, int countComponents)
{
    mark[v] = 1;
    components[v] = countComponents;
    for (int i = 0; i < list[v].size(); i++)
    {
        if (mark[list[v][i]] == 0)
        {
            DFS2(list, mark, components, list[v][i], countComponents);
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int> > list(n, vector<int>());
    vector<vector<int> > listR(n, vector<int>());
    vector<bool> mark(n, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        list[a].push_back(b);
        listR[b].push_back(a);
    }

    vector<int> topSort;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 0)
        {
            DFS1(list, mark, i, topSort);
        }
    }

    mark.assign(n, 0);

    int countComponents = 1;
    vector<int> components(n, 0);
    for (int i = 0; i < n; i++)
    {
        int v = topSort[n - 1 - i];
        if (mark[v] == 0)
        {
            DFS2(listR, mark, components, v, countComponents);
            countComponents++;
            components.clear();
        }
    }

    cout << --countComponents << endl;
    for (int i = 0; i < n; i++)
    {
        cout << components[i] << ' ';
    }
    return 0;
}