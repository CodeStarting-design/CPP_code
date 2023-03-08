#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;
int main(){
    list<string> l1(10,"aaa");
    vector<const char*> v1(5,"bbb");
    vector<const char*> v2(10,"ccc");
    swap(v1,v2);
    cout<<v1.size()<<" "<<v2.size()<<endl;
}