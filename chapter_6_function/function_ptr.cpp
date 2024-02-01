#include<iostream>
int test(int *a){
    *a=10;
    return 0;
}
int main(){
    int c=2,*b=&c;
    test(b);
    std::cout<<c;
    return 0;
}