/* ************************************************************************
> File Name:     string_constructor.cpp
> Author:        mark
> Created Time:  2023年03月07日 星期二 09时10分44秒
> Description:   
 ************************************************************************/
#include<iostream>
#include<string>
using namespace std;
int main(){
    const char *cp="hello";
    char cp2[]={
        'h','e','l','l','o','\0'
    };
    cout<<5<<cp[5]<<endl;
    int i=0;
    for(auto a:cp2){
        cout<<i++<<" "<<a<<" ";
    }
    cout<<endl;
    string s(cp);
    string s1(cp2);
    cout<<s<<" "<<s1<<endl;
    string s2(cp+2,1,1);
    cout<<s2<<endl;
    return 0;
}
