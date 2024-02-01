#include<iostream>
int main(){
    int a=10,*p=&a;
    decltype(*p) c=a;  // 此时c是a的一个引用
    decltype(&p) i=&p; // 此时i是指向p的一个指针
    c=2; // 本质上是在修改a的值
    std::cout<<a;
    **i=3;
    std::cout<<a;
}