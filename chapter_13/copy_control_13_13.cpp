#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;
struct X{
    X(){cout<<"X()"<<endl;}// 构造函数
    X(const X&){cout<<"X(const X&)"<<endl;}// 拷贝构造函数 编译器可以自动略过
    X& operator=(const X& ){cout<<"X& operator=(const X& )"<<endl; return *this;}
    ~X(){cout<<"~X()"<<endl;}
};
void test_1(X x1){
    cout<<"非引用类型"<<endl;
}
void test_2(X& x1){
    cout<<"引用类型"<<endl;
}
int main(){
    X* p1=new X(); // 调用构造函数
    test_1(*p1);// 调用拷贝构造函数 调用析构函数
    test_2(*p1);// 不需要
    vector<X> vec(1,X());// 先调用构造函数再调用拷贝构造函数，然后完成拷贝之后，创建的临时对象也会被析构
    delete p1;// 调用析构函数
}// 调用析构函数