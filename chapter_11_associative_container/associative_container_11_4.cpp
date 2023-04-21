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
        string word_l;
        for(auto &a:word)
            word_l+=std::tolower(a);// 转小写
        word_l.erase(std::remove_if(word_l.begin(),word_l.end(),ispunct),word_l.end());
        word_count[word_l]++;
    }
    for(auto a:word_count)
        cout<<a.first<<" "<<a.second<<std::endl;
}