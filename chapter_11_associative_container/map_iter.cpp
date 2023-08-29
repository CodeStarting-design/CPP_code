#include<iostream>
#include<map>
#include<string>
#include<utility>
using std::map;
using std::string;
using std::pair;
int main(){
    map<int,int> m={{1,1},{2,2},{3,3}};
    auto miter=m.begin();
    ++miter->second;
    std::cout<<miter->first<<" "<<miter->second;
}