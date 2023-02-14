#include<iostream>
#include<cctype>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<int> num(10);
    for(auto &a:num)
    cin>>a;
    for(auto it = num.begin();it!=num.end();it++)
    (*it)*=2;
    for(auto it =num.begin();it!=num.end();it++)
    cout<<*it<<endl;

    return 0;

}