#include<bits/stdc++.h>
using namespace std;

int x,y;
int ans;

int gcd(int a,int b)
{
    return (b==0?a:gcd(b,a%b));
}

int main()
{
    cin>>x;
    cin>>y;
    for(int i=1;i<=y;i++)
    {
        if(y%i!=0)continue;
        int j=y*x/i;
        if(gcd(i,j)==x)ans++;
    }
    cout<<ans;
    return 0;
}