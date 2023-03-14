#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool select_size(const string &s1){
    if(s1.size()<5){
        return false;
    }
    return true;
}
int main(){
    vector<string> vec;
    string s;
    while(cin>>s) 
    vec.push_back(s);
    auto true_end=partition(vec.begin(),vec.end(),select_size);
    vector<string>::iterator it=vec.begin();
    while(it!=true_end){
        cout<<*(it++)<<" ";
    }
    cout<<endl;
}