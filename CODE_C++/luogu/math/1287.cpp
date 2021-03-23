#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, r;
    cin >> n;
    cin >> r;
    int s[11][11];
    memset(s, 0, sizeof(s));
    s[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            if(i==j&&j==1||i<j)continue;
            else if(i==j)
                s[i][j]=1;
            else
                s[i][j] = j * s[i - 1][j] + s[i - 1][j - 1];
        }
    }
    int temp = 1;
    for (int i = 2; i <= r; i++)
        temp *= i;
    cout << (temp * s[n][r]);
    return 0;
}