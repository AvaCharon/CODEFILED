#include<iostream>

template<typename T>//template(class)实现不同类型参数的输入
void swap2(T &a,T &b)
{
    T temp=a;
    a=b;
    b=temp;
    return;
}
int main()
{
    using namespace std;
    int a,b;
    cin>>a>>b;
    swap2(a,b);
    cout<<a<<" "<<b;
    return 0;
}