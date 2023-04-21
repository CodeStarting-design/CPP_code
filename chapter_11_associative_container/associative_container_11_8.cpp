#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using std::string;
int main(){
    std::vector<string> vec;
    string word;
    while(std::cin>>word){
        if(std::find(vec.begin(),vec.end(),word)==vec.end())
            vec.push_back(word);
    }
    for(auto &a:vec)
        std::cout<<a<<" ";
}