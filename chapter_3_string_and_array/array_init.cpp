#include<iostream>
using std::cout;
int b[10]={1};
int main(){
    int a[10]={1}; // 
    cout<<a[1]<<std::endl;
    for(auto i:b)
    cout<<i;
    for(auto i:a)
    cout<<i;
    return 0;
}