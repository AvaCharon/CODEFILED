//最大公因数
int gcd(LL a, LL b)
{
    return (b == 0 ? a : gcd(b, a % b));
}


//最小公倍数
int lcm(LL a, LL b)
{
    return a * b / gcd(a, b);
}





//卡特兰数

#include <bits/stdc++.h>
using namespace std;

int f[20];
int n;

int main()
{
    cin >> n;
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            f[i] += f[j] * f[i - j - 1];
        }
    }
    cout << f[n];
    return 0;
}





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






















//线性筛素数
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int ask[q];//所求素数标号
    for(int i=0;i<q;i++)
    {
        scanf("%d",&ask[i]);
    }
    int primes[n], cnt = 0; // 所有素数
    bool st[n];             // x是否被筛掉
    memset(primes, 0, sizeof(primes));
    memset(st, false, sizeof(st));
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    for(int i=0;i<q;i++)
    {
        printf("%d\n",primes[ask[i]-1]);
    }
    return 0;
}









//第一类斯特林数：
//给出 n  个不同的数，选出 m  个非空圆排列，问有多少种方案？
/*
原理：
定义s1[i][j]表示 i  个不同数形成 j 个圆排列的方案数。这个状态很明显可以由两个状态转移过来：
第一个：i − 1  个数形成 j − 1 个圆排列，那么新加入的数只需要新形成一个圆排列就可以了。
第二个：i − 1  个数形成 j 个圆排列，那么新的数必须加入到原来的 j 个排列中去。显然加入到原来的 i − 1 个数的任意一个数的左边都是不同的。
那么总的方案数就是s1[i][j]=s1[i-1][j-1]+s1[i-1][j]*(i-1)。
*/

typedef long long ll;

const int N = 105;
ll s1[N][N];
void stirling1()
{
    s1[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            s1[i][j] = s1[i - 1][j] * (i - 1) + s1[i - 1][j - 1];
        }
    }
}
















//第二类斯特林数：
//给定 n  个不同的数，将这 n 个数分成 m  个非空的集合，问有多少种不同的方案？

/*
原理
和第一类斯特林数一样，s2[i][j]表示将 i  个数分成 j  个集合，也有两种情况：
第一个：i − 1  个数分成了 j − 1  个集合，那么新的数只需要放入新的几个就可以了。
第二个：i − 1  个数分成了 j 个集合，那么新的那个数就必须放入这 j  个集合任意一个。
*/

const int N = 105;
ll s2[N][N];
void stirling2()
{
    s2[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            s2[i][j] = s2[i - 1][j] * j + s2[i - 1][j - 1];
        }
    }
}





//最大子序和
int maxSubArray(vector<int> &nums)
{
    int pre = 0, maxAns = nums[0];
    for (const auto &x : nums)
    {
        pre = max(pre + x, x);
        maxAns = max(maxAns, pre);
    }
    return maxAns;
}

