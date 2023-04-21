#include<iostream>
#include<set>
#include<map>
#include<string>
using std::string;
using std::multimap;
using std::multiset;
using std::cin;
using std::cout;
int main(){
    multimap<string,string> authors={
        {"mike","nice"},
        {"jack","man"},
        {"mike","Deep"},
        {"jack","learning"},
        {"jack","transfprmer"}
    };
    std::map<string,multiset<string>> author;
    for(auto a:authors){
        author[a.first].insert(a.second);
    }
    for(auto a:author){
        cout<<a.first<<" ";
        for(auto c:a.second)
            cout<<c<<" ";
        cout<<std::endl;
    }
}