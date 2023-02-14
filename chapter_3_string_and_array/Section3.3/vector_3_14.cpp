#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<int> num;
    vector<string> str;
    int n;
    string s;
    for(int i=0;i<10;i++){
        cin>>n;
        num.push_back(n);
    }
    for(int i=0;i<10;i++){
        cin>>s;
        str.push_back(s);
    }
    for(auto a:num)
    cout<<a<<" ";
    cout<<endl;
    for(auto b:str)
    cout<<b<<" ";
    cout<<endl;    
    
}