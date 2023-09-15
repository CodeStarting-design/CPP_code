#include<iostream>
#include<string>
#include<memory>
#include<cstring>
using std::string;
int main(){
    string s;
    std::cin>>s;
    char *a=new char[s.size()];
    for(int i=0;i<s.size();i++)
        a[i]=s[i];
    std::cout<<a<<std::endl;
}