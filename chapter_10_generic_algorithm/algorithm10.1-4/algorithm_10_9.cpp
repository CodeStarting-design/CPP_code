#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> vec;
    int n;
    while(cin>>n) 
    vec.push_back(n);
    sort(vec.begin(),vec.end());
    auto un_end=unique(vec.begin(),vec.end());
    vec.erase(un_end,vec.end());
    for(auto a:vec)
    cout<<a<<" ";
    cout<<endl;
}