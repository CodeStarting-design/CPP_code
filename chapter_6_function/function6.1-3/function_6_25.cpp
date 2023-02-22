#include<iostream>
#include<string>
using namespace std;
int main(int argc,char* argv[]){
    cout<<argc<<endl;
    string s="";
    // 此处是在传参，那么argv本质上是一个指针，不能范围for
    for(int i=0;i<argc;i++)
    s+=argv[i];
    cout<<s<<endl;
    return 0;
}