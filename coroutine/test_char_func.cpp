#include<iostream>
void fun(char * a){
    std::cout<<static_cast<void*>(a)<<" "<<static_cast<void*>(&a)<<std::endl;
}
int main(){
    char *a=new char(10);
    std::cout<<static_cast<void*>(a)<<std::endl;
    fun(a);
}