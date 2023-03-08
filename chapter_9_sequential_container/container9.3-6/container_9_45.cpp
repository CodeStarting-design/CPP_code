/* ************************************************************************
> File Name:     container_9_45.cpp
> Author:        mark
> Created Time:  2023年03月07日 星期二 10时52分36秒
> Description:   
 ************************************************************************/
#include<iostream>
#include<string>
using namespace std;
string generate_name(string name,string pre,string suf){
    name.insert(name.begin(),pre.begin(),pre.end());
    name.append(suf);
    return name;
}
int main(){
    string name="mark";
    string pre="dear";
    string suf="wang";
    name=generate_name(name,pre,suf);
    cout<<name<<endl;
}
