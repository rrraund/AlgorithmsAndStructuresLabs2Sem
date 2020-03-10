#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, a, b;
    cin >> n >> m;
    int list[m][2];
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        list[i][0] = min(a, b);
        list[i][1] = max(a, b);
        matrix[list[i][0]][list[i][1]]++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] > 1)
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}