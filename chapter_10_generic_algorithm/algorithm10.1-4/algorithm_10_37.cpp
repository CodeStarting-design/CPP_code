#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
int main(){
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,0};
    std::list<int> l;
    std::copy(vec.rbegin()+3,vec.rend()-2,std::insert_iterator(l,l.begin()));
    for(auto a:l)
    std::cout<<a<<" ";
    std::cout<<std::endl;
}