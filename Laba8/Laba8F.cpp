#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void restore(vector<int> &road, int distance, int start, int finish, int width)
{
    int d = distance;
    stack<char> s;
    int number = finish;
    for (int i = 0; i < distance - 1; i++)
    {
        d--;
        if (road[number - 1] == d)
        {
            s.push('R');
            number -= 1;
        }
        else if (road[number + 1] == d)
        {
            s.push('L');
            number += 1;
        }
        else if (road[number - width] == d)
        {
            s.push('D');
            number -= width;
        }
        else if (road[number + width] == d)
        {
            s.push('U');
            number += width;
        }
    }
    if (road[number - 1] == -1)
    {
        s.push('R');
    }
    else if (road[number + 1] == -1)
    {
        s.push('L');
    }
    else if (road[number - width] == -1)
    {
        s.push('D');
    }
    else if (road[number + width] == -1)
    {
        s.push('U');
    }
    cout << distance << endl;
    for (int i = 0; i < distance; i++)
    {
        cout << s.top();
        s.pop();
    }
}

void BFS(vector<vector <int> > &list, vector<int> &mark, vector<int> &d, int start, int finish, int width)
{
    queue<int> q;
    q.push(start);
    d[start] = 0;
    mark[start] = -1;
    mark[finish] = -2;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < list[v].size(); i++)
        {
            if (mark[list[v][i]] == -2)
            {
                d[list[v][i]] = d[v] + 1;
                mark[list[v][i]] = d[list[v][i]];
                restore(mark, mark[list[v][i]], start, finish, width);
                return;
            }
            if (mark[list[v][i]] == 0)
            {
                d[list[v][i]] = d[v] + 1;
                mark[list[v][i]] = d[list[v][i]];
                q.push(list[v][i]);
            }
        }
    }
    cout << -1;
}


int main()
{
//    ios_base::sync_with_stdio(false);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector <char> > map(n + 2, vector<char>(m + 2));
    vector<vector <int> > list((n + 2) * (m + 2),vector<int>());
    vector<int> mark((n + 2) * (m + 2), 0);
    vector<int> distance((n + 2) * (m + 2), 0);
    int start, finish;
    int width = m + 2;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] == '.' || map[i][j] == 'S' || map[i][j] == 'T')
            {
                if (map[i - 1][j] == '.' || map[i - 1][j] == 'S' || map[i - 1][j] == 'T')
                {
                    list[i * width + j].push_back((i - 1) * width + j);
                }
                if (map[i + 1][j] == '.' || map[i + 1][j] == 'S' || map[i + 1][j] == 'T')
                {
                    list[i * width + j].push_back((i + 1) * width + j);
                }
                if (map[i][j - 1] == '.' || map[i][j - 1] == 'S' || map[i][j - 1] == 'T')
                {
                    list[i * width + j].push_back(i * width + (j - 1));
                }
                if (map[i][j + 1] == '.' || map[i][j + 1] == 'S' || map[i][j + 1] == 'T')
                {
                    list[i * width + j].push_back(i * width + (j + 1));
                }
            }
            if (map[i][j] == 'S')
            {
                start = i * width + j;
            }
            if (map[i][j] == 'T')
            {
                finish = i * width + j;
            }
        }
    }
    BFS(list, mark, distance, start, finish, m + 2);
    return 0;
}