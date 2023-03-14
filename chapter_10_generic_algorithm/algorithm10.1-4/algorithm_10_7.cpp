#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<list>
using namespace std;
int main(){
    vector<int> vec2;
    vec2.reserve(10);
    fill_n(vec2.begin(),10,0);
    list<int> l1;
    int i;
    while(cin>>i)
    l1.push_back(i);
    vector<int> vec;
    copy(l1.begin(),l1.end(),back_inserter(vec));
    for(auto a:vec)
    cout<<a<<" ";
    cout<<endl;
    for(auto a:vec2)
    cout<<a<<" ";
    cout<<endl;
}