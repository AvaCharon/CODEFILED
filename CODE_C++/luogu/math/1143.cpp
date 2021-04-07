//进制转换
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ins[41];
    int in[41], out[41];
    int n, m, sum = 0;
    scanf("%d%s\n%d", &n, ins, &m);
    int i;
    for (i = 0; ins[i]; i++)
    {
        if (isdigit(ins[i]))
            in[i] = ins[i] - '0';
        else
            in[i] = ins[i] - 'A' + 10;
    }
    for (int j = i - 1; j >= 0; j--)
        sum += in[j] * pow(n, i - 1 - j);
    int j = 0;
    while (sum >= 1)
    {
        out[j++] = sum % m;
        sum /= m;
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