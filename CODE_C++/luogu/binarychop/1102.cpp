#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c;
    long long ans = 0;
    cin >> n >> c;
    long long f[n];
    map<int, long long> m;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
        m[f[i]]++;
    }
    sort(f,f+n);
    for (int i = 0; i < n; i++)
    {
        ans += m[c + f[i]] * m[f[i]];
        m[f[i]] = 0;
    }
    cout << ans << endl;
    return 0;
}

//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;

int a[maxn];
map<int, long long> mmp;
int n, c;
int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        mmp[a[i]] = mmp[a[i]] + 1;
    }
    sort(a + 1, a + n + 1);
    int len = unique(a + 1, a + n + 1) - a - 1;
    long long ans = 0;
    for (int i = 1; i <= len; i++)
    {
        ans += mmp[a[i]] * mmp[a[i] + c];
    }
    printf("%lld\n", ans);
    return 0;
}
