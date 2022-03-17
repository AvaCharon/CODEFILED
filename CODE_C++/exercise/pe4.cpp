#include <bits/stdc++.h>
using namespace std;

int main()
{
    double f[3] = {9.4458, 19.125, 29.46667};
    double a[3];
    double ans = 0;
    for (int i = 0; i < 3; i++)
    {
        f[i]/=180;
        a[i] = 3333.333333 * sin(f[i]) / (i + 1);
        cout << a[i] << endl;
        ans += a[i];
    }
    cout << ans / 3;
    return 0;
}