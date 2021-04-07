//位运算
#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n;
    scanf("%ull", &n);
    printf("%u", (n & 0x0000ffff) << 16 | (n & 0xffff0000) >> 16);
    return 0;
}