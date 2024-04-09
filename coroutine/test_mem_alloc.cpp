#include<iostream>
using namespace std;
#define STACK_SIZE (1024*1024)
struct test{
int n;
char c;
char stack[STACK_SIZE];
test():n(0),c('a'){};
};
void func(){
    int a=0;
    cout<<"函数局部变量的内存地址： "<<static_cast<void*>(&a)<<endl;
}
int main(){
    int a=0;
    cout<<static_cast<void*>(&a)<<endl;
    test* t=new test();
    cout<<"t 中保存的内存地址： "<<static_cast<void*>(t)<<"  t 的内存地址： "<<static_cast<void*>(&t)<<endl;
    cout<<"n的内存地址： "<<static_cast<void*>(&(t->n))<<endl;
    cout<<"n的内存地址： "<<static_cast<void*>(&(t->c))<<endl;
    cout<<"stack的内存地址： "<<static_cast<void*>(t->stack)<<endl;
    func();
    delete t;
    return 0;
}