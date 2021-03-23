#include<bits/stdc++.h>
using namespace std;

int n;
long long ans=1;
int w[52];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    sort(w,w+n);
    for(int i=0;i<n;i++)
    {
        if(w[i]-i<=0)
        {
            cout<<"0";
            return 0;
        }
        long long temp=(w[i]-i)%1000000007;
        ans*=temp;
        ans%=1000000007;
    }
    cout<<ans;
    return 0;
}