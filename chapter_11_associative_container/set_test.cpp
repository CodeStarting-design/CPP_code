#include<iostream>
#include<map>
#include<string>
#include<set>
using std::string;
using std::map;
using std::endl;
using std::cout;
using std::cin;
using std::set;
int main(){
    map<string,int> word_count;
    string word;
    set<string> ex={"aaa","bbb"};
    while(cin>>word){
        if(ex.find(word)==ex.end()) // 不存在++
            word_count[word]++;
    }
    for(auto a:word_count)
    cout<<a.first<<" "<<a.second<<endl;
}