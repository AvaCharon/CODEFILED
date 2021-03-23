//The Blocks Problem uva101
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

const int maxn = 30;
vector<int>pile[maxn];//一维大小不超过30，二维是动态的
int n;

void FindBlock(int a,int &p,int &h)
{
    for(p=0;p<n;p++)
    {
        for(h=0;h<pile[p].size();h++)
        {
            if(pile[p][h]==a)return;
        }
    }   
}

void ClearAbove(int p,int h)
{
    for(int i=h+1;i<pile[p].size();i++)
    {
        int b=pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h+1);
    return;
}

void PileOnto(int p,int h,int p2)
{
    for(int i=h;i<pile[p].size();i++)
    {
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);
    return;
}

void print()
{
    for(int i=0;i<n;i++)
    {
        printf("%d:",i);
        for(int j=0;j<pile[i].size();j++)
        {
            printf(" %d",pile[i][j]);
        }
        printf("\n");
    }
    return;
}

int main()
{
    int a,b;
    cin>>n;
    string s1,s2;
    for(int i=0;i<n;i++)pile[i].push_back(i);
    while (cin>>s1>>a>>s2>>b)
    {
        int pa,pb,ha,hb;
        FindBlock(a,pa,ha);
        FindBlock(b,pb,hb);
        if(pa==pb)continue;
        if(s2=="onto")ClearAbove(pb,hb);
        if(s1=="move")ClearAbove(pa,ha);
        PileOnto(pa,ha,pb);
    }
    print();
    return 0;
}