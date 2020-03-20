#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point
{
    int x;
    int y;
};

int distancePow2(Point a, Point b)
{
    int d = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
    return d;
}

void primMst(vector<vector<int> > &matrix, vector<bool> &mark, vector<int> &distances, int start)
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
        mark[v] = true;
        for (int j = 0; j < n; j++)
        {
            if (!mark[j] && matrix[v][j] < distances[j] && v != j)
            {
                distances[j] = matrix[v][j];
            }
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    freopen("spantree.in", "r", stdin);
    freopen("spantree.out", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int> > matrix(n, vector<int>(n));
    vector<bool> mark(n, false);
    vector<int> distances(n, 1000000000);
    vector<Point> points(n);

    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = distancePow2(points[i], points[j]);
        }
    }

    primMst(matrix, mark, distances, 0);

    double lengthMst = 0;
    for (int i = 0; i < n; i++)
    {
        lengthMst += sqrt(distances[i]);
    }

    cout << setprecision(10) << lengthMst;
    return 0;
}