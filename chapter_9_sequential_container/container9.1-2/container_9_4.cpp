#include<iostream>
#include<vector>
using namespace std;
bool find_num(vector<int>::iterator first,vector<int>::iterator last,int num){
    for(;first!=last&&*first!=num;first++);
    return first!=last;
}
int main(){
    vector<int> vec(10,0);
    vec[5]=10;
    cout<<find_num(vec.begin(),vec.end(),20);
}