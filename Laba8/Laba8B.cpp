#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    bool matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                cout << "NO";
                return 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}