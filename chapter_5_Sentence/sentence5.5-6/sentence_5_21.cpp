#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;
int main(){
    vector<string> strs;
    string str,pstr="";
    while(cin>>str){
        if(!isupper(str[0])){
            continue;
        }
        if(pstr==str){
            cout<<str<<endl;
            break;
        }
        pstr=str;
    }
    return 0;
}