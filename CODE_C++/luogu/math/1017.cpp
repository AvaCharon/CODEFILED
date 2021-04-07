//负进制转换
//商++，余数-=除数
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int out[41];
    int m, sum = 0;
    scanf("%d%d", &sum, &m);
    printf("%d=", sum);
    int j = 0;
    while (abs(sum) >= 1)
    {
        if (sum % m < 0)
        {
            out[j++] = sum % m - m;
            sum /= m;
            sum++;
        }
        else
        {
            out[j++] = sum % m;
            sum /= m;
        }
    }
    for (j--; j >= 0; j--)
    {
        if (out[j] < 10)
            cout << out[j];
        else
            printf("%c", out[j] - 10 + 'A');
    }
    printf("(base%d)", m);
    return 0;
}