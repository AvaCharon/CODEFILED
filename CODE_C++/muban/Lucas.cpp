//卢卡斯定理
//求C(n,n+m)mod(p)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll q_pow(ll a,ll b,ll p)//快速幂用来求逆元 
{
    ll ans=1;
    while(b) 
    {
        if(b&1)
            ans=(ans*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ans;
}

ll comb(ll a,ll b,ll p)//求组合数 
{
    if(a<b)    return 0;
    if(b==a) return 1;
    if(b>a-b) b=a-b;
    ll ans=1,ca=1,cb=1;
    for(int i=0; i<b; i++) 
    {
        ca=(ca*(a-i))%p;
        cb=(cb*(b-i))%p;
    }
    ans=(ca*q_pow(cb,p-2,p))%p;
    return ans;
}

ll lucas(ll a,ll b,ll p)//lucas 
{
    ll ans=1;
    while(a&&b&&ans) 
    {
        ans=(ans*comb(a%p,b%p,p))%p;
        a/=p;
        b/=p;
    }
    return ans%p;
}

int main() 
{
    ll t,n,m,p;
    cin>>t;
    while(t--) 
    {
        cin>>n>>m>>p;
        cout<<lucas(n+m,n,p)<<endl;
    }
    return 0;
}