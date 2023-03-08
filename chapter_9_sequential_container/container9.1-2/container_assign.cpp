#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;
int main(){
    list<string> l1(10,"aaa");
    vector<const char*> v1(5,"bbb");
    l1.assign(v1.cbegin(),v1.cend());
    for(auto &a:l1)
    cout<<a<<endl;
    cout<<l1.size()<<endl;
}