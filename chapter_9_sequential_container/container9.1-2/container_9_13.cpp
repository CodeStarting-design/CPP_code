#include<iostream>
#include<vector>
#include<array>
#include<list>
using namespace std;
int main(){
    vector<double> v1(10);
    list<int> l1(10);
    vector<double> v2(l1.begin(),l1.end());
    list<int> l2(v1.begin(),v1.end());
    // array<int,10> a1(l1.begin(),l1.end());
}