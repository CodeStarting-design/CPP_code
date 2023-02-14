#include<iostream>
using namespace std;
int main(){
    int x=1,y=3;
    bool value=false;
    cout<<(value?++x,++y:--x,--y)<<endl;
    return 0;
}