#include<iostream>
#include<vector>
using namespace std;
vector<int>::iterator find_num(vector<int>::iterator first,vector<int>::iterator last,int num){
    for(;first!=last&&*first!=num;first++);
    return first;
}
int main(){
    vector<int> vec(10,0);
    vec[5]=10;
    vector<int>::iterator res = find_num(vec.begin(),vec.end(),10);
    if(res!=vec.end())
    cout<<*res<<endl;
}