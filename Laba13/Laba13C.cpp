#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vint;


void prefixFunction (vint &prefixForIndex, string s)
{
    int n = s.length();
    for (int i = 1; i < n; i++)
    {
        int j = prefixForIndex[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = prefixForIndex[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        prefixForIndex[i] = j;
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    string s;
    cin >> s ;

    int n = s.length();
    vint prefixForIndex(n, 0);
    prefixFunction(prefixForIndex, s);
    for (int i = 0; i < n; i++)
    {
        cout << prefixForIndex[i] << ' ';
    }

    return 0;
}