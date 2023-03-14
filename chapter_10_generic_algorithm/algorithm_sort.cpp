#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool isShorter(const string &s1,const string &s2){
    return s1.size()<s2.size();
}
int main(){
    vector<string> vec;
    string s;
    while(cin>>s) 
    vec.push_back(s);
    sort(vec.begin(),vec.end());
    auto un_end=unique(vec.begin(),vec.end());
    vec.erase(un_end,vec.end());
    stable_sort(vec.begin(),vec.end(),isShorter);
    for(auto a:vec)
    cout<<a<<" ";
    cout<<endl;
}