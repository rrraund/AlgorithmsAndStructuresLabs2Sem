#include <iostream>
#include <vector>

using namespace std;
const long long INF = 1000000000;


void floyd(vector<vector<int> > &matrix)
{
    int n = matrix.size();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    freopen("pathsg.in", "r", stdin);
    freopen("pathsg.out", "w", stdout);

    int n, m, a, b, w;
    cin >> n >> m;

    vector<vector<int> > matrix(n, vector<int>(n, INF));

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        a--;
        b--;
        matrix[a][b] = w;
    }

    floyd(matrix);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 0;
            }
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}