#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;
int main(){
    vector<string> str;
    string s;
    int n=10;
    while(n--){
        getline(cin,s);
        str.push_back(s);
    }
    for(auto &a:str){
        for(auto &b:a)
        b=toupper(b);
    }
    for(auto a:str)
    cout<<a<<endl;
    return 0;
}