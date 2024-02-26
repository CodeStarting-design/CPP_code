#include<iostream>
int main(){
    const int i=0;
    int d=0;
    const int* a = &i;
    int const* b = &i;
    int* const c = &d;
    std::cout<<a<<" "<<b<<" "<<c<<" ";
}