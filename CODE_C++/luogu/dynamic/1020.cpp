/*
#include <bits/stdc++.h>
using namespace std;
int n = 0;
int h[100010];
int maxn = 0;

int main()
{
    while (cin >> h[++n]);
    n--;
    int f[n + 2]; //从i开始拦截的最大拦截数
    for (int i = n; i >= 1; i--)
    {
        f[i] = 1;
        for (int j = i + 1; j <= n; j++)
        {
            if ((h[j] <= h[i]) && (f[j] + 1 > f[i]))
                f[i] = f[j] + 1;
        }
        maxn = max(maxn, f[i]);
    }
    int k = 1;
    memset(f, 0, sizeof(f));
    f[1] = h[1];
    for (int i = 2; i <= n; i++)
    {
        if (h[i] <= f[k])
            f[k] = h[i];
        else
            f[++k] = h[i];
    }
    cout << maxn << endl
         << k << endl;
    return 0;
}
*/

//最长不上升子序列
//最长上升子序列

/*
//O(n^2) dp Wrong
#include <bits/stdc++.h>
using namespace std;
int n = 0;
int h[100010];

int main()
{
    while (cin >> h[++n])
        ;
    n--;
    int f[n + 3]; //前i个的最长子序列，且以i结尾
    int maxn = 0;
    for (int i = 1; i <= n; i++)
        f[i] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (h[i] <= h[j])
                f[i] = max(f[i], f[j] + 1);
        }
        maxn = max(maxn, f[i]);
    }
    cout << maxn << endl;

    int k = 1;
    for (int i = 2; i <= n; i++)
    {
        if (h[i] > h[i - 1])
            k++;
    }
    cout << k << endl;
    return 0;
}
*/


//
//O(n^2) dp correct
#include <bits/stdc++.h>
using namespace std;
int n = 0;
int h[100010];

int main()
{
    while (cin >> h[++n])
        ;
    n--;
    int f[n + 3]; //前i个的最长子序列，且以i结尾
    int maxn = 0;
    for (int i = 1; i <= n; i++)
        f[i] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (h[i] <= h[j])
                f[i] = max(f[i], f[j] + 1);
        }
        maxn = max(maxn, f[i]);
    }
    cout << maxn << endl;

    maxn = 0;
    for (int i = 1; i <= n; i++)
        f[i] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (h[i] > h[j])
                f[i] = max(f[i], f[j] + 1);
        }
        maxn = max(maxn, f[i]);
    }
    cout << maxn << endl;
    return 0;
}

/*
//O(nlogn) dp+二分查找
#include<bits/stdc++.h>
using namespace std;


int main()
{

    return 0;
}
*/

/*

#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans1,ans2,f[100001],a[100001];
int main(){
    while(scanf("%d",&a[++n])!=EOF);
    n--;//要-1，不然n就不是正确的n了 
    for(int i=n;i>=1;i--){//注意！！因为它是以i开头的最长不上升子序列，所以这里要从n开始循环，不然会出现一些奇妙的bug 
        f[i]=1;//以第i个数开头的最长不上升子序列的长度至少为1（当这个序列只有它本身这一个数） 
        for(int j=i+1;j<=n;j++){//用前面已经算好的来算现在正在算的这一个 
            if(a[j]<=a[i])//如果a[j]>a[i]的话就不满足不上升这个要求（毕竟a[j]在a[i]后面） 
                f[i]=max(f[i],f[j]+1); //更新f[i]~记得要+1啊 
        }
        ans1=max(ans1,f[i]);//更新ans1 
    }
    for(int i=1;i<=n;i++){//同上，因为它是以i结尾的最长上升子序列，所以这里要从前往后，不然会出现一些奇妙的bug
        f[i]=1;//以第i个数结尾的最长上升子序列的长度至少为1（当这个序列只有它本身这一个数） 
        for(int j=1;j<i;j++){
            if(a[j]<a[i])//如果a[j]>=a[i]的话就不满足上升这个要求（毕竟a[j]在a[i]前面） 
                f[i]=max(f[i],f[j]+1);//更新f[i]~记得要+1啊 
        }
        ans2=max(ans2,f[i]);//更新ans2 
    }
    printf("%d\n%d\n",ans1,ans2);
}
*/

/*
O(n2)树状数组
#include<cstdio>
#include<cstring>
#include<algorithm>
 
using namespace std;
int n,maxn,ans1,ans2,f[1000001],a[1000001];
 
int lowbit(int x){return x&-x;}
 
void add(int x,int c){ 
    for(int i=x;i<=maxn;i+=lowbit(i)) f[i]=max(f[i],c);//维护最大值 
}
 
int query(int x){
    int res=0;
    for(int i=x;i>=1;i-=lowbit(i)) res=max(res,f[i]);//求以小于等于x的数为结尾的最长不上升子序列的长度的最大值 
    return res;
}
 
 
int main(){
    while(scanf("%d",&a[++n])!=EOF) maxn=max(maxn,a[n]);
    n--;//要-1，不然n就不是正确的n了 
    for(int i=n;i>=1;i--){//从后往前循环 
        int q=query(a[i])+1;//查询以小于等于x的数为开头的最长不上升子序列的长度的最大值
        add(a[i],q);//这个最大值+1就是以当前这个数开头的最长不上升子序列的长度，丢到树状数组里面去 
        ans1=max(ans1,q); 
    }
    printf("%d\n",ans1);
    memset(f,0,sizeof(f));//还是memset一下比较保险 
    for(int i=1;i<=n;i++){//从前往后循环 
        int q=query(a[i]-1)+1;//查询以小于（没有等于！！！）x的数为结尾的最长上升子序列的长度的最大值
        add(a[i],q);//这个最大值+1就是以当前这个数结尾的最长上升子序列的长度，丢到树状数组里面去 
        ans2=max(ans2,q);
    }
    printf("%d\n",ans2);
}

*/