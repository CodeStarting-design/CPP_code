#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<string> v1{10};
    vector<string> v2{10,"aa"};
    for (auto a:v1)
    cout<<a<<endl;
    for(auto b:v2)
    cout<<b<<endl;
    return 0;
}
