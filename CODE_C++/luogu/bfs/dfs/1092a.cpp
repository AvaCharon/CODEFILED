//别人写的
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n;
char s[3][30];
int a[3][30],vis[30],ans[30];
int flag=0;
 
bool CHECK(){
	int A,B,C;
	for(int i=0;i<n;i++){
		A=ans[ a[0][i] ];B=ans[ a[1][i] ];C=ans[ a[2][i] ];
		if( A==-1 || B==-1 || C==-1 )continue;
		if( (A+B)%n!=C && (A+B+1)%n!=C ) return 1;
	}
	return 0;
} 
int check1() {
	for(int i=0;i<n;i++)
		if(vis[i]==0)return 0; 
	return 1;
}
bool check2(){
	int A,B,C,x=0;
	for(int i=0;i<n-1;i++){
		A=ans[ a[0][i] ];B=ans[ a[1][i] ];C=ans[ a[2][i] ];
		if( (A+B+x)%n!=C )return 0;
		x=(A+B+x)/n;
	}
	return 1;
}
void print()
{
    for(int i=0;i<n-1;i++)printf("%d ",ans[i]);
	printf("%d\n",ans[n-1]);
    flag=1;
}
 
void dfs(int row,int col,int x){/*行，列，进位*/ 
	if(flag)return;
	if( CHECK() )return;
	if(check1()){
		if(check2()){
			print();
			flag=1;
		}
		return;
	}  
	 
    int t=a[row][col];
    if(row!=2){
        if(ans[t]==-1){
            for(int i=n-1;i>=0;i--)
                if(!vis[i]){
                    vis[i]=1;ans[t]=i;
                    dfs(row+1,col,x);
                    vis[i]=0;ans[t]=-1;							
                }
        }
        else dfs(row+1,col,x);
    }
    else{
        int A=ans[ a[0][col] ],B=ans[ a[1][col] ];
        int tmp=A+B+x;
        if(ans[t]==-1){	
            if(!vis[tmp%n]){
            	ans[t]=tmp%n;vis[ans[t]]=1;
                dfs(0,col+1,tmp/n);
                vis[ans[t]]=0;ans[t]=-1;
            }	
        }
        else {
            if(tmp%n==ans[t])dfs(0,col+1,tmp/n);
            else return;
        }
    }	
}
 
int main(){
    memset(ans,-1,sizeof(ans));
    cin>>n;
    cin>>s[0]>>s[1]>>s[2];
    for(int i=0;i<n;i++){
        a[0][i]=s[0][n-1-i]-'A';a[1][i]=s[1][n-1-i]-'A';a[2][i]=s[2][n-1-i]-'A';
    }
    dfs(0,0,0);
    return 0;
}