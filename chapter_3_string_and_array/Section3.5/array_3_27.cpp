#include<iostream>
using namespace std;
int text_size(){
    return 10;
}
int main(){
    int a[text_size()];
    int a1[1+3];
    for(auto c:a)
    cout<<c<<endl;
    for(auto &c:a1)
    cin>>c;
    int a2[10]={1};
    cout<<a2[0]<<a2[1]<<endl;
    return 0;
}