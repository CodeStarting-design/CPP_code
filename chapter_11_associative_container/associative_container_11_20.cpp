#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<cctype>
using std::string;
using std::map;
using std::cin;
using std::cout;
int main(){
    map<string,int> word_count;
    string word;
    while(cin>>word){
        auto a=word_count.insert({word,1});
        if(!a.second){
            a.first->second++;
        }
    }
    for(auto a:word_count)
        cout<<a.first<<" "<<a.second<<std::endl;
}