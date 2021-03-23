/*
#include <bits/stdc++.h>
using namespace std;
int a[20][20];
int f[20][20];
int px[20][20];
int py[20][20];
int n;

int main()
{
    cin >> n;
    int x = -1, y = 1, z = 1;
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));
    while (x != 0 && y != 0 && z != 0)
    {
        cin >> x >> y >> z;
        a[x][y] = z;
    }
    f[1][1] = a[x][y];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                continue;
            f[i][j] = a[i][j] + max(f[i - 1][j], f[i][j - 1]);
            if (f[i - 1][j] > f[i][j - 1])
            {
                px[i][j] = i - 1;
                py[i][j] = j;
            }
            else
            {
                px[i][j] = i;
                py[i][j] = j - 1;
            }
        }
    }
    cout << f[n][n] << endl;
    return 0;
}
*/
/*
//subset[i][j]=max(subset[i-1][j],subset[i][j-1])+map[i][j];
#include <bits/stdc++.h>
using namespace std;
int subset[12][12];
int mapp[12][12];
int sum = 0;

int main()
{
    memset(mapp, 0, sizeof(mapp));
    int x = 1, y = 1, z = 1, n;
    cin >> n;
    while (x != 0 && y != 0 && z != 0)
    {
        cin >> x >> y >> z;
        mapp[x][y] = z;
    }
    for (int k = 0; k < 2; k++)
    {
        memset(subset, 0, sizeof(subset));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; i++)
            {
                if (i == 1 && j == 1)
                {
                    subset[1][1] = mapp[1][1];
                    mapp[1][1] = 0;
                    continue;
                }
                subset[i][j] = max(subset[i - 1][j], subset[i][j - 1]) + mapp[i][j];
                if (subset[i - 1][j] > subset[i][j - 1])
                {
                    mapp[i - 1][j] = 0;
                }
                else
                {
                    mapp[i][j - 1] = 0;
                }
            }
        }
        sum += subset[n][n];
    }
    cout << sum << endl;
    return 0;
}
*/
/*
//f[i][j][k][l]=max(max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k-1][l],f[i][j-1][k][l-1]))+v[i][j]+v[k][l];
#include <bits/stdc++.h>
using namespace std;
int f[11][11][11][11]; //两人坐标
int v[11][11];         //格子价值
int n, x = 1, y = 1, z = 1;
int main()
{
    cin >> n;
    while (x != 0 || y != 0 || z != 0)
    {
        cin >> x >> y >> z;
        v[x][y] = z;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                for (int l = 1; l <= n; l++)
                {
                    f[i][j][k][l] = max(max(f[i - 1][j][k - 1][l], f[i - 1][j][k][l - 1]), max(f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1])) + v[i][j] + v[k][l];
                    if (i == k && l == j)
                        f[i][j][k][l] -= v[i][j];
                }
            }
        }
    }
    cout << f[n][n][n][n];
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int f[11][11][11][11];
int v[11][11];
int n, x = 1, y = 1, z = 1;
int main()
{
    cin >> n;
    while (x != 0 && y != 0 && z != 0)
    {
        cin >> x >> y >> z;
        v[x][y] = z;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                for (int p = 1; p <= n; p++)
                {
                    f[i][j][k][p] = max(f[i - 1][j][k - 1][p], max(f[i][j - 1][k - 1][p], max(f[i - 1][j][k][p - 1], f[i][j - 1][k][p - 1]))) + v[i][j] + v[k][p];
                    if (i == k && j == p)
                        f[i][j][k][p] -= v[i][j];
                }
            }
        }
    }
    cout << f[n][n][n][n];
    return 0;
}