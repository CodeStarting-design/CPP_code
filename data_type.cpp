#include<iostream>
using namespace std;
int main(){
    int i=0,&r1=i;
    double d=3.1,&r2=d;
    r1=d;
    cout<<r1<<endl;
    return 0;
}