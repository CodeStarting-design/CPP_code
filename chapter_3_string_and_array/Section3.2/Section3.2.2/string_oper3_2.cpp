#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1;
    while(getline(cin,s1)){
        if(s1!="#")
        cout<<s1<<endl;
        else break;
    }
    while(cin>>s1){
        if(s1!="#")
        cout<<s1<<endl;
        else break;
    }
    return 0;
}