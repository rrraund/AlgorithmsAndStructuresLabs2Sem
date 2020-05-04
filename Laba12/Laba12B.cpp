#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<bool> vbool;


//Kuhn
bool mt(vvint &list, vbool &mark, vint &matching, int prev)
{
    int n = list[prev].size();
    if (mark[prev])
    {
        return false;
    }
    mark[prev] = true;
    for (int i = 0; i < n; i++)
    {
        int next = list[prev][i];
        if (matching[next] == -1 || mt(list, mark, matching, matching[next]))
        {
            matching[next] = prev;
            return true;
        }
    }
    return false;
}



int main()
{
    ios_base::sync_with_stdio(false);
    freopen("matching.in", "r", stdin);
    freopen("matching.out", "w", stdout);

    int n1, n2, m, a1, a2;
    cin >> n1 >> n2 >> m;

    vvint list(n1, vint());
    vint matching(n2, -1);
    vbool markMt(n1);
    vbool markAll(n1);

    for (int i = 0; i < m; i++)
    {
        cin >> a1 >> a2;
        a1--;
        a2--;
        list[a1].push_back(a2);
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < list[i].size(); j++)
        {
            if (matching[list[i][j]] == -1)
            {
                matching[list[i][j]] = i;
                markAll[i] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n1; i++)
    {
        if (markAll[i])
        {
            continue;
        }
        for (int j = 0; j < n1; j++)
        {
            markMt[j] = false;
        }
        mt(list, markMt, matching, i);
    }

    int countMt = 0;
    for (int i = 0; i < n2; i++)
    {
        if (matching[i] != -1)
        {
            countMt++;
        }
    }
    cout << countMt;

    return 0;
}