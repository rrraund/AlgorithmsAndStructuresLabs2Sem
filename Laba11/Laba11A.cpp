#include <iostream>
#include <vector>

using namespace std;
const long long INF = 1000000000000;


void dijkstra(vector<vector<long long> > &matrix, vector<bool> &mark, vector<long long> &distances, int start)
{
    distances[start] = 0;
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
        {
            if (!mark[j] && (v == -1 || distances[j] < distances[v]))
            {
                v = j;
            }
        }
        if (distances[v] == INF)
        {
            break;
        }
        mark[v] = true;
        for (int j = 0; j < n; j++)
        {
            distances[j] = min(distances[j], distances[v] + matrix[v][j]);
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);

    int n, start, finish;
    cin >> n >> start >> finish;
    start--;
    finish--;

    vector<vector<long long> > matrix(n, vector<long long>(n));
    vector<bool> mark(n, false);
    vector<long long> distances(n, INF);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = INF;
            }

        }
    }

    dijkstra(matrix, mark, distances, start);

    if (distances[finish] < INF)
    {
        cout << distances[finish];
    }
    else
    {
        cout << -1;
    }
}