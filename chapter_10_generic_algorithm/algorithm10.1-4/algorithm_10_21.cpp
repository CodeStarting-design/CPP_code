#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main(){
    int a=10;
    auto f=[&a]()->bool {if(a==0) return true;while(a)a--; return false;};
    cout<<f()<<endl;
    cout<<f()<<endl;
}