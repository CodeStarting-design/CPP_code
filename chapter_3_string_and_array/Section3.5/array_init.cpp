#include<iostream>
using namespace std;
int main(){
    int a=10;
    cin>>a;
    int b[a];
    for(auto &c:b)
    cin>>c;
    for(auto &c:b)
    cout<<c<<endl;
    return 0;
}