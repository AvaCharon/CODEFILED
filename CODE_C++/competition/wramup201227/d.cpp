#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if(n%(m+1))
        cout<<"Leins";
    else
        cout<<"Linners";
    return 0;
}