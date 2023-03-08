/* ************************************************************************
> File Name:     container_9_43.cpp
> Author:        mark
> Created Time:  2023年03月07日 星期二 10时21分07秒
> Description:   
 ************************************************************************/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void replace_str(string &s,string oldVal,string newVal){
    // 此处在进行元素的插入与删除时，需要注意的迭代器的改变
    // 此处的查找使用find函数实现
    string::size_type pos=0;
    while((pos=s.find(oldVal,pos))!=string::npos){
        s.erase(pos,oldVal.size());
        s.insert(pos,newVal);
        pos+=newVal.size()-1;
    }
}
int main(){
    string s="hello world thro  ts hello aaa ts yyy ts";
    string oldVal="ts";
    string newVal="theShy";
    replace_str(s,oldVal,newVal);
    cout<<s<<endl;
}
