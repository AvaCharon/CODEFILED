
/*
//二维
//f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+v[i])
#include <bits/stdc++.h>
using namespace std;
int f[33][20010]; //前i个，总容量，能达到的最小剩余量
int n, m;         //个数，容量
int v[33];

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j >= v[i])
            {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + v[i]);
            }
            else
            {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    cout << m - f[n][m] << endl;
    return 0;
}

*/
//一维数组
#include <bits/stdc++.h>
using namespace std;
int f[20010]; //第i次，总容量，能达到的最小剩余量
int n, m;     //个数，容量
int v[33];

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            if (j >= v[i])
                f[j] = max(f[j], f[j - v[i]] + v[i]);
        }
    }
    cout<<m-f[m]<<endl;
    return 0;
}