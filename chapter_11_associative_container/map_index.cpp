#include<iostream>
#include<map>
using std::map;
int main(){
    map<int,int> a;
    a[1]=0;
    std::cout<<a[1]<<std::endl;
    std::cout<<a.at(1)<<std::endl;
    const map<int,int> c={
        {1,2},
        {2,3}
    };
    std::cout<<c.at(1)<<std::endl;
}