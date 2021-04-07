//异或的性质
#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        ans ^= m;
    }
    printf("%d", ans);
    return 0;
}