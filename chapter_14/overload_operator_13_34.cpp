#include<iostream>
struct test{
    test(){} // 或者选择不写，直接；将会导致只是声明，但是没有定义
    int operator() (int a,int b,int c) const {
        if(a){
            return b;
        }
        return c;
    }
};
int main(){
    test a;
    std::cout<<a(1,2,3);
    return 0;
}