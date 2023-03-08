/* ************************************************************************
> File Name:     container_9_46.cpp
> Author:        mark
> Created Time:  2023年03月07日 星期二 11时06分15秒
> Description:   
 ************************************************************************/
#include<iostream>
#include<string>
using namespace std;
string generate_name(string name,string pre,string suf){
    name.insert(0,pre);
    name.insert(name.size(),suf);
    return name;
}
int main(){
    string name="mark";
    string pre="dear";
    string suf="wang";
    name=generate_name(name,pre,suf);
    cout<<name<<endl;
}
