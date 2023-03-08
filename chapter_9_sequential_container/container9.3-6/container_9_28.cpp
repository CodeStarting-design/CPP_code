/* ************************************************************************
> File Name:     container_9_28.cpp
> Author:        mark
> Created Time:  2023年03月05日 星期日 11时39分17秒
> Description:   
 ************************************************************************/
#include<iostream>
#include<forward_list>
#include<string>
using namespace std;
void insert_string(forward_list<string> &l1,string s1,string s2){
    forward_list<string>::iterator iter1=l1.begin(),iter2=l1.before_begin();
    while(iter1 != l1.end()&&*iter1 != s1){
        iter2=iter1;
        iter1++;
    }
    if(iter1==l1.end())
        l1.insert_after(iter2,s2);
    else
        l1.insert_after(iter1,s2);
}
void print(forward_list<string> l1){
    for(auto &a:l1)
        cout<<a<<" ";
    cout<<endl;
}
int main(){
    forward_list<string> fl1={
        "123","aaa","vvvv","iii","ooo","rrr"
    };
    string s1="aaa",s2="bbb";
    insert_string(fl1,s1,s2);
    print(fl1);
    s1="qqq",s2="ccc";
    insert_string(fl1,s1,s2);
    print(fl1);
}
