#include<iostream>
double trandu(double dcal)
{
    double dfah=1.8*dcal+32.0;
    return dfah;
}
int main(void)
{
    using namespace std;
    double dcal;
    cout<<"Input a Celsius value:";
    cin>>dcal;
    cout<<dcal<<" degrees Calsius is "<<trandu(dcal)<<" degrees Fahrenheit"<<endl;
    return 0;
}