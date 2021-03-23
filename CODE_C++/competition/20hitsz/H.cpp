//状压dp

#include<bits/stdc++.h>
using namespace std;

long long f[1000005][2];//0平1突两种接口
long n;

int main()
{
    cin>>n;
    f[1][0]=1;
    f[1][1]=0;
    f[2][1]=2;
    f[2][0]=2;
    for(int i=3;i<=n;i++)
    {
        f[i][0]=f[i-1][0]%10000+f[i-1][1]%10000+f[i-2][0]%10000;
        f[i][1]=(f[i-2][0]*2)%10000+f[i-1][1]%10000;
    }
    cout<<f[n][0]%10000;
    return 0;
}