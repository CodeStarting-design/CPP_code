#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1;
    cout<<"Please input s1"<<endl;
    cin>>s1;
    cout<<s1<<endl;
    while(getline(cin,s1)){
        cout<<s1<<endl;
    }
    return 0;
}