#include<iostream>
#include<iomanip>
int main(void)
{
    using namespace std;
    double a;
    cin>>a;
    cout<<a<<endl;//默认6精度（整数部分加小数部分）
    cout<<showpoint<<a<<endl;//小数形式不显示0
    cout.setf(ios_base::showpoint);//显示最后的0补齐位数
    cout<<a<<endl;
    cout.precision(6);
    cout<<a<<endl;
    cout<<fixed<<setprecision(2);//fix表示精度仅计算小数后
    cout<<a;
    return 0;
}

