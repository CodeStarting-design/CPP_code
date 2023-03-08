#include<iostream>
#include<list>
#include<deque>
using namespace std;
int main(){
    list<int> l1={1,2,3,4,5,6};
    deque<int> q1;
    deque<int> q2;
    for(auto &a:l1)
    if(a%2)
    q1.push_back(a);
    else
    q2.push_back(a);
    for(auto &a:q1)
    cout<<a<<endl;
    for(auto &a:q2)
    cout<<a<<endl;
}