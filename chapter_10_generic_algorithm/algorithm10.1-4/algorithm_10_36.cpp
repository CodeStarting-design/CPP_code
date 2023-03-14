#include<algorithm>
#include<list>
#include<iterator>
#include<iostream>
int main(){
    std::list<int> l{1,2,3,4,50,2,0,3,0,4,5,6,0,3,4};
    auto iter=std::find(l.rbegin(),l.rend(),0);
    std::cout<<*iter<<std::endl;
}