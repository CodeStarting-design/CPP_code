/* ************************************************************************
> File Name:     container_9_47.cpp
> Author:        mark
> Created Time:  2023年03月07日 星期二 11时33分37秒
> Description:   
 ************************************************************************/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string num="0123456789";
vector<string::size_type> find_num(string s){
    vector<string::size_type>numPos;
    string::size_type pos=0;
    while((pos=s.find_first_of(num,pos))!=string::npos){
        numPos.push_back(pos);
        pos++;
    }
    return numPos;
}
vector<string::size_type> find_letter(string s){
    vector<string::size_type> letterPos;
    string::size_type pos=0;
    while((pos=s.find_first_not_of(num,pos))!=string::npos){
        letterPos.push_back(pos);
        pos++;
    }
    return letterPos;
}
int main(){
    string s="a2n123jkbn4uj3j45kj";
    vector<string::size_type> numPos=find_num(s);
    vector<string::size_type> letterPos=find_letter(s);
    for(auto a:numPos)
        cout<<a<<" ";
    cout<<endl;
    for(auto a:letterPos)
        cout<<a<<" ";
    cout<<endl;
}
