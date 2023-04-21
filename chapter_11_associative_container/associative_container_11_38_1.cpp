#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<fstream>
using std::unordered_map;
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::ifstream;
int main(){
    string word;
    unordered_map<string,int> word_count;
    while(cin>>word){
        if(word_count.find(word)!=word_count.end()){
            word_count[word]++;
        }else{
            word_count[word]=0;
        }
    }
    for(auto &a:word_count)
        cout<<a.first<<" "<<a.second<<" ";
    cout<<std::endl;
    return 0;
}