#include<iostream>
#include<vector>
#include<iterator>
int main(){
    std::vector<int> vec{1,2,3,34,4,5,6,7};
    for(auto iter=vec.rbegin();iter!=vec.rend();iter++)
    std::cout<<*iter<<" ";
    std::cout<<std::endl;
}