#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vint;


void kmp(vint &prefixForIndex, string p, string t, int &countWords, vint &indexes)
{
    string s = p + '#' + t;
    int m = p.length();
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
        if (j == m)
        {
            countWords++;
            indexes.push_back(i - 2 * m);
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    freopen("search2.in", "r", stdin);
    freopen("search2.out", "w", stdout);

    string p, t, s;
    int m , n;
    cin >> p >> t;

    m = p.length();
    n = t.length();

    vint prefixForIndex(n + m + 1);
    vint indexes;
    int countWords = 0;

    kmp(prefixForIndex, p, t, countWords, indexes);

    cout << countWords << endl;
    for (int i = 0; i < countWords; i++)
    {
        cout << indexes[i] + 1 << ' ';
    }

    return 0;
}