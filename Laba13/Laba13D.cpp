#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vint;
typedef vector<vint> vvint;


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


void automatKmp(vvint &ak47, int alphabet, string s)
{
    s += '#';
    int n = s.length();

    vint prefixForIndex(n);
    prefixFunction(prefixForIndex, s);

    for (int i = 0; i < n; i++)
    {
        for (int c = 0; c < alphabet; c++)
        {
            if (i > 0 && c + (int)('a') != (int)(s[i]))
            {
                ak47[i][c] = ak47[prefixForIndex[i - 1]][c];
            }
            else
            {
                ak47[i][c] = i + (c + (int)('a') == (int)(s[i]));
            }
        }
    }
}



int main()
{
    int alphabet;
    cin >> alphabet;

    string s;
    cin >> s;
    
    int n = s.length();

    vvint ak47(n + 1, vint(alphabet));
    automatKmp(ak47, alphabet, s);

    for (int i = 0; i < ak47.size(); i++)
    {
        for (int j = 0; j < ak47[0].size(); j++)
        {
            cout << ak47[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}