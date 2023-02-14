#include<iostream>
using namespace std;
int main(){
    typedef double d,*p;
    d d1=2.1;
    p r1=&d1;
    cout<<*r1<<"  "<<r1<<endl;
    using I=int; //此处I就是int的别名，需要通过哦赋值语句实现
    using Q=int*;
    int i1=100;
    Q r2=&i1;
    cout<<*r2<<endl;
    typedef char *pstring;
    char a=100;
    const pstring c1=&a;
    pstring *str;
    auto a1=d1,*a2=&d1;
    return 0;
}