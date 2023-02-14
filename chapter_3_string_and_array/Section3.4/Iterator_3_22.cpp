#include<iostream>
#include<cctype>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<string> str(10);
    for(auto &s:str)
    getline(cin,s);
    for(auto it=str.begin();it!=str.end()&&!it->empty();it++){
     for(auto &s:(*it)){
        s=toupper(s);
     }
     cout<<*it<<endl;
    }
    return 0;

}