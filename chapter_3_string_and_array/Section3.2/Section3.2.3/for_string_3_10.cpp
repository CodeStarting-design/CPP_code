#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    string str;
    for(auto a:s)
    if(!ispunct(a))
    str+=a;
    cout<<str<<endl;
    return 0;
}