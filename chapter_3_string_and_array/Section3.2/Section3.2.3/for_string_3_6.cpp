#include<iostream>
#include<string>
#include<cctype>
#include<typeinfo>
using namespace std;
int main(){
    string s;
    cin>>s;
    for(auto &a:s)
    {
      a='X';
      cout<<typeid(a).name()<<endl;
    
    cout<<s<<endl;
    string str;
    cout<<str[0]<<endl;
    return 0;
}