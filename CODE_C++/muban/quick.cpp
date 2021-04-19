#include <bits/stdc++.h>
using namespace std;
//usual
long long quick_pow(int a, int b)
{
    long long ans = 1, base = a;
    while (b)
    {
        if (b & 1)
            ans *= base;
        base *= base;
        b >>= 1;
    }
    return ans;
}

long long quick_mul(int a, int b)
{
    long long ans = 0, base = a;
    while (b)
    {
        if (b & 1)
            ans += base;
        base += base;
        b >>= 1;
    }
    return ans;
}

//mod
typedef long long ll;
ll quickpow(ll a, ll b, ll mod)
{
    ll ans = 1, base = a;
    while (b)
    {
        if (b & 1)
            ans = (ans * base) % mod;
        base = (base * base) % mod;
        b >>= 1;
    }
    return ans;
}

ll quickmul(ll a, ll b, ll mod)
{
    ll ans = 0, base = a;
    while (b)
    {
        if (b & 1)
            ans = (ans + base) % mod;
        base = (base + base) % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<quick_pow(a,b)<<endl;
    cout<<pow(a,b);
    return 0;
}