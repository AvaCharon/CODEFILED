#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    long int i=1;
    double term,sum,pi;
    i=1,sum=1;
    term=1.0/4;
    cout<<term<<endl;
    do
    {
        i=i+1;
        term=1/(i*i);
        sum=sum+term;
    }while(term>=1e-12);
    pi=sqrt(sum*6);
    cout<<"pi="<<pi<<endl;
    system("pause");
    return 0;
}