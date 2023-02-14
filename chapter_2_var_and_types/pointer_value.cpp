#include<iostream>
using namespace std;
int main(){
    int a=10;
    int *p;
    p=&a;
    cout<<*p<<" "  <<p<<endl;
    int *p1=&a;
    int *p2=p1;
    p2=p1;
    int c=1;
    int *p4=&c;
    void *d=p;
    double s=3.12,*p3=&s;
    d=p3;
    return 0;
}