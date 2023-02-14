#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<string> strs;
    string str,pstr="";
    while(cin>>str){
        if(pstr==str){
            cout<<str<<endl;
            break;
        }
        pstr=str;
    }
    return 0;
}