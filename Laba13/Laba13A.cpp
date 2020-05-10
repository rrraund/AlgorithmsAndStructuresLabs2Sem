#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vint;



int main()
{
    ios_base::sync_with_stdio(false);
    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);

    string p, t;
    int m , n;
    cin >> p >> t;

    m = p.length();
    n = t.length();

    vint indexes;
    int countWords = 0;
    int i = 0, j = 0;
    while(i <= n - m)
    {
        for (j = 0; j < m; j++)
        {
            if (t[i + j] != p[j])
            {
                break;
            }
        }
        if (j == m)
        {
            indexes.push_back(i);
            countWords++;
        }
        i++;
    }

    cout << countWords << endl;
    for (i = 0; i < countWords; i++)
    {
        cout << indexes[i] + 1 << ' ';
    }

    return 0;
}