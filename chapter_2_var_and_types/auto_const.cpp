#include<iostream>
using namespace std;
int main(){
    int i=0,&r=i;
    const int ci=i,&cr=ci; //cr是一个常量的引用
    auto b=ci;//b应该是一个int类型，不会保存顶层const
    auto c=cr;//cr是一个常量的引用，保存底层const
    auto d=&i; //d是指向int类型的指针
    auto e=&ci;//是指向const int 的指针
    //定义顶层const
    const auto f=ci;//此时f是一个常整型
    int g=10;
    double h=10.2;
    decltype(g=h) j=g; //此处返回的是一个int&类型
    cout<<j<<endl;
    return 0;
}