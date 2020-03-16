#include <iostream>
#include <vector>

using namespace std;

void DFS1(vector<vector <int> > &list, vector<int> &mark, int v);
void DFS2(vector<vector <int> > &list, vector<int> &mark, int v);

void DFS1(vector<vector <int> > &list, vector<int> &mark, int v)
{
    for (int i = 0; i < list[v].size(); i++)
    {
        if (mark[list[v][i]] == 2)
        {
            mark[v] = 1;
            return;
        }
        if (mark[list[v][i]] == 0)
        {
            DFS2(list, mark, list[v][i]);
        }
        if (mark[list[v][i]] == 1)
        {
            mark[v] = 1;
            return;
        }
    }
    mark[v] = 2;
}

void DFS2(vector<vector <int> > &list, vector<int> &mark, int v)
{
    for (int i = 0; i < list[v].size(); i++)
    {
        if (mark[list[v][i]] == 1)
        {
            mark[v] = 2;
            return;
        }
        if (mark[list[v][i]] == 0)
        {
            DFS1(list, mark, list[v][i]);
        }
        if (mark[list[v][i]] == 2)
        {
            mark[v] = 2;
            return;
        }
    }
    mark[v] = 1;
}



int main()
{
    ios_base::sync_with_stdio(false);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    int n, m, a, b, start;
    cin >> n >> m;
    cin >> start;
    --start;

    vector<vector<int> > list(n, vector<int>());
    vector<int> mark(n, 0);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        list[a].push_back(b);
    }

    DFS1(list, mark, start);
    if (mark[start] % 2 == 1)
    {
        cout << "First player wins";
    }
    else
    {
        cout << "Second player wins";
    }
    return 0;
}