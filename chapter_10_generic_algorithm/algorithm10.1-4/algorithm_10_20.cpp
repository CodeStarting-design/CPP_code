#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool isLonger(const string &s1){
    return s1.size()>6;
}
int main(){
    vector<string> vec;
    string s;
    while(cin>>s)
    vec.push_back(s);
    int count=count_if(vec.begin(),vec.end(),isLonger);
    cout<<count<<endl;
}