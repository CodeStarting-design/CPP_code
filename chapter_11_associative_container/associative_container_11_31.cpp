#include<iostream>
#include<map>
#include<string>
using std::multimap;
using std::string;
using std::cout;
using std::cin;
int main(){
    multimap<string,string>authors;
    string name,book;
    while(name!="#"){
        cin>>name;
        cin>>book;
        authors.insert({name,book});
    }
    string key;
    cin>>key;
    for(auto a:authors)
    cout<<a.first<<" "<<a.second<<std::endl;
    auto iter=authors.find(key);
    if(iter!=authors.end())
    authors.erase(iter);
    for(auto a:authors)
    cout<<a.first<<" "<<a.second<<std::endl;
}