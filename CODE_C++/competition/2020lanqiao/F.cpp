#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a;
    int tmp = a;
    int ans1, ans2;
    double ans3 = 0;
    while (tmp--)
    {
        cin >> b;
        if (tmp == a - 1)
            ans1 = ans2 = b;
        else
        {
            ans1 = max(ans1, b);
            ans2 = min(ans2, b);
        }
        ans3 += b;
    }
    ans3 /= a;
    printf("%d\n%d\n%.2lf", ans1, ans2, ans3);
    return 0;
}