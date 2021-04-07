//负进制转换
//商++，余数-=除数
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int out[41];
    int m, sum = 0;
    scanf("%d%d", &sum, &m);
    int j = 0;
    while (abs(sum) >= 1)
    {
        out[j++] = sum % m - m;
        sum /= m;
        sum++;
    }
    for (j--; j >= 0; j--)
    {
        if (out[j] < 10)
            cout << out[j];
        else
            printf("%c", out[j] - 10 + 'A');
    }
    return 0;
}