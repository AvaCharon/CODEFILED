#include<bits/stdc++.h>
using namespace std;

double fun1(double x){
    return x*x*(exp(x)-exp(1));
}

double fun2(double x){
    return 2*x/(1-2*x);
}

int main()
{
    int N = 10;
    double x = 1;
    double h = (double)2/N;
    cout<<"N="<<N<<endl;
    for(int i=0;i<=N;i++){
        cout<<fun2(x)<<", ";
        x+=h;
    }
    return 0;
}