#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
using std::placeholders::_1;
bool isShorter(const std::string &s,int sz){
    return s.size()>=sz;
}
int main(){
    std::vector<std::string> vec;
    std::string s;
    while (std::cin>>s)
    {
        vec.push_back(s);
    }
    int count=count_if(vec.begin(),vec.end(),bind(isShorter,_1,7));
    std::cout<<count<<std::endl;
}