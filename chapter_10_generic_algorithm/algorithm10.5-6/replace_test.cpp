#include<algorithm>
#include<iostream>
#include<vector>
int main(){
    std::vector<int> vec{1,2,3,4,5,1,2,3,2,3};
    std::replace(vec.begin(),vec.end(),2,10);
    for(auto a:vec)
    std::cout<<a<<" ";
}