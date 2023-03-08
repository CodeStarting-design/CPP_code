#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main(){
    string s;
    deque<string> q1;
    while(cin>>s){
        q1.push_back(s);
    }
    for(deque<string>::iterator iter=q1.begin();iter!=q1.end();iter++)
    cout<<*iter<<endl;
}