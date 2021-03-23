#include<iostream>
#include<fstream>

int main()
{
    using namespace std;

    char automobile[50];
    int year;
    double a_price,d_price;
    ofstream outfile;
    outfile.open("Outcpp.txt");//新建文件，若已有则打开（打开时从头截断原有内容）

    cout<<"Enter the make and model of automobile:";
    cin.getline(automobile,50);
    cout<<"Enter the model year:";
    cin>>year;
    cout<<"Enter the original asking price:";
    cin>>a_price;
    d_price=0.913*a_price;

    cout<<fixed;//流操作符fixed:表示浮点输出应该以固定点或小数点表示法表示
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout<<"Make and model:"<<automobile<<endl;
    cout<<"Year:"<<year<<endl;
    cout<<"Was asking $"<<a_price<<endl;
    cout<<"Now asking $"<<d_price<<endl;

    outfile<<fixed;
    outfile.precision(2);
    outfile.setf(ios_base::showpoint);
    outfile<<"Make and model:"<<automobile<<endl;
    outfile<<"Year:"<<year<<endl;
    outfile<<"Was asking $"<<a_price<<endl;
    outfile<<"Now asking $"<<d_price<<endl;

    outfile.close();//
    return 0;
}