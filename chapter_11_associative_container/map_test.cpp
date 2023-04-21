#include<iostream>
#include<map>
#include<string>
using std::string;
using std::map;
using std::endl;
using std::cout;
using std::cin;
int main(){
    map<string,int> word_count;
    string word;
    while(cin>>word)
    word_count[word]++;
    for(auto a:word_count)
    cout<<a.first<<" "<<a.second<<endl;
}