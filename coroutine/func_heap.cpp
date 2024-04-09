#include<iostream>
void func1(){
    char *a=new char(2);// 在堆上分配空间
    std::cout<<static_cast<void*>(a)<<" "<<static_cast<void*>(&a[1])<<std::endl;
    delete a;
}
void func2(){
    char *a=new char(2);// 在堆上分配空间
    std::cout<<static_cast<void*>(a)<<" "<<static_cast<void*>(&a[1])<<std::endl;
    delete a;
}
int main(){
    char *a=new char(2);// 在堆上分配空间
    std::cout<<static_cast<void*>(a)<<" "<<static_cast<void*>(&a[1])<<std::endl;
    func1();
    func2();
    delete a;
}