#include<iostream>
#include<list>
#include<algorithm>
#include<string>
using std::string;
using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::stable_sort;
bool isShorter(const string &s1,const string &s2){
    return s1.size()<s2.size();
}
int main(){
    list<string> l;
    string s;
    while(cin>>s)
    l.push_back(s);
    // 主序是字符串长度，次序是首字母
    l.sort();
    l.unique();
    for(auto a:l)
    cout<<a<<" ";
    cout<<endl;
}
