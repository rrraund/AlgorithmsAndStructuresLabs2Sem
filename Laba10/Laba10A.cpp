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
    vector<vector<int> > list(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        cout << list[i].size() << ' ';
    }
    return 0;
}