#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>
namespace VECTOR
{
    class Vector
    {
        double x;
        double y;
        double mag;
        double ang;
        char mode;
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
        
        public:
        Vector();//无参构造函数
        Vector(double n1,double n2,char form ='r');//有参构造函数
        //成员函数
        void set(double n1,double n2,char form ='r');//避免修改对象内部数据时用构造函数时的额外步骤
        ~Vector();//析构函数
        double xval()const{return x;}
        double yval()const{return y;}
        double magval()const{return mag;}
        double angval()const{return ang;}
        void polar_mode();
        void rect_mode();
        //重载运算符
        Vector operator +(const Vector &b)const;//a+b
        Vector operator -(const Vector &b)const;//a-b
        Vector operator -()const;//-a
        Vector operator *(double n)const;//a*n;

        friend Vector operator*(double n,const Vector &a);//实现n*a;
        friend std::ostream &operator<<(std::ostream & os,const Vector &v);//cout<<v;
    };
}
#endif

