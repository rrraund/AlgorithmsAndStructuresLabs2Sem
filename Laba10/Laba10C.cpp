#include <iostream>
#include <vector>
#include <queue>

typedef unsigned long long ulong;

using namespace std;

ulong primMst(vector<vector<pair<int, int> > > &list, vector<bool> &mark)
{
    ulong sumMinWeight = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        pair<int, int> vertexWeightPair = q.top();
        q.pop();
        int dis = vertexWeightPair.first;
        int ver = vertexWeightPair.second;

        if (mark[ver])
        {
            continue;
        }
        mark[ver] = true;

        sumMinWeight += dis;

        int size = list[ver].size();
        for (int i = 0; i < size; i++)
        {
            int v = list[ver][i].first;
            int d = list[ver][i].second;
            if (!mark[v])
            {
                q.push(make_pair(d, v));
            }
        }
    }
    return sumMinWeight;
}



int main()
{
    ios_base::sync_with_stdio(false);
    freopen("spantree3.in", "r", stdin);
    freopen("spantree3.out", "w", stdout);

    int n, m, a, b, w;
    cin >> n >> m;

    vector<vector<pair<int, int> > > list(n, vector<pair<int, int> >());
    vector<bool> mark(n, false);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        a--;
        b--;
        list[a].push_back(make_pair(b, w));
        list[b].push_back(make_pair(a, w));
    }

    ulong sumWeightMst = primMst(list, mark);
    cout << sumWeightMst;
    return 0;
}