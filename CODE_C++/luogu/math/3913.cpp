#include <bits/stdc++.h>
using namespace std;

long long n, k;
const int maxn = 1e6 + 5;
long long x[maxn], y[maxn];

int main()
{
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    sort(x, x + k);
    sort(y, y + k);
    long long xl = unique(x, x + k) - x;
    long long yl = unique(y, y + k) - y;
    printf("%lld", n * n - (n - xl) * (n - yl));
    return 0;
}