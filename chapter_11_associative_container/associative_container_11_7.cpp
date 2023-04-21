#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<iterator>
using std::string;
int main(){
    std::map<string,std::vector<string>> family;
    string family_name;
    string last_name;
    // std::istream_iterator<string> in_iter(std::cin),eof;
    while(std::cin>>family_name&&family_name!="@q"){
        family[family_name];
        while(std::cin>>last_name&&last_name!="@q")
            family[family_name].push_back(last_name);
    }
    string addName;
    while(std::cin>>addName&&addName!="@q"){
        std::cin>>last_name;
        family[addName].push_back(last_name);
    }
    for(auto &a:family){
        std::cout<<a.first<<" ";
        for(auto &c:a.second)
            std::cout<<c<<" ";
        std::cout<<std::endl;
    }
}