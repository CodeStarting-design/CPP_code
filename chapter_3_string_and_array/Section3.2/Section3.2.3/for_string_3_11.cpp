#include<iostream>
#include<string>
using namespace std;
int main(){
    const string str="Hello world!";
    for(auto &a:str)
    cout<<a<<endl;
    return 0;
}