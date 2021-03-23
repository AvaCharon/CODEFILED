#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=1e6+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a) memset(a,0,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first 
#define se second
ll ksm(ll a,ll n,ll p){
	ll ans=1;
	while(n){
		if(n&1) ans=ans*a%p;
		a=a*a%p;
		n>>=1;
	}
	return ans;
}
ll fac[N];
int p;
ll C(ll n,ll m){	//组合数&费马小定理. 
	if(n<m) return 0;
	return fac[n]*ksm(fac[m]*fac[n-m]%p,p-2,p)%p;
}	
ll Lucas(ll n,ll m){	//递归求解. 
	if(!m) return 1;
	return C(n%p,m%p)*Lucas(n/p,m/p)%p;
} 
int main(){
	int t; 
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d%d",&n,&m,&p);
		fac[0]=1;
		for(int i=1;i<=p;i++) fac[i]=fac[i-1]*i%p;
		printf("%lld\n",Lucas(n+m,n));
	}
	return 0;
}


//

#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
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