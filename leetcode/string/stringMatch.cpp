#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    string subStr;
    cin>>str>>subStr;
    int i=0,j=0;
    while(i<str.size()&&j<subStr.size()){
        if(str[i]==subStr[j])
        j++;
        else 
        i=i-j,j=0;
        i++;
    }
    if(j==subStr.size())
    cout<<i-j<<endl;
    else cout<<-1<<endl;
    return 0;
}