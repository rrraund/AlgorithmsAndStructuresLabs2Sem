#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, a, b;
    cin >> n >> m;
    vector<vector <int> > matrix(n,vector<int>(n));
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
        matrix[--a][--b] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}