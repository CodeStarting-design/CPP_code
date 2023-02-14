#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1>s2)
    cout<<s1<<endl;
    else
    cout<<s2<<endl;
    s1.size()>s2.size()?cout<<s1<<endl:cout<<s2<<endl;
    return 0;
}
