#include<iostream>
#include<string>
using namespace std;
bool str_subrange(const string &str1,const string &str2){
    if(str1.size()==str2.size())
    return str1.size()==str2.size();
    auto size=(str1.size()>str2.size())?str2.size():str1.size();
    for(decltype(size) i=0;i!=size;i++){
        if(str1[i]!=str2[i])
        return true; // 单纯处理报错
    }
    return true; // 单纯处理报错
}
int main(){
string str1("wdhuye");
string str2("dgasuad");
bool flag=str_subrange(str1,str2);
cout<<flag<<endl;
}