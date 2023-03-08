#include<iostream>
#include<list>
#include<vector>
#include<string>
using namespace std;
int main(){
    list<const char *> l1(2 ,"aaa"); // 此处的“aaa”是一个字面值常量，所以最好使用const char*指针
    vector<string> v1(10);
    v1.assign(l1.cbegin(),l1.cend());
    for(auto &a:v1)
    cout<<a<<endl;
}