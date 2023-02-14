#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector<string> str{"aa","aasa"};
    for(auto a:str)
    cout<<a<<endl;
    str={"aa"};
    cout<<str.size()<<endl;
    return 0;
}