#include<iostream>
using namespace std;
int main(){
    const double d1=3.2626;
    const double *r1=&d1;
    // double *r2=&d1;
    double d2=2.3;
    const double *r2=&d2;
    int i2=10;
    int *const p2=&i2;
    cout<<*p2<<" "<<p2<<endl;
    *p2=100;
    cout<<i2<<endl;
    int s1=100;
    int *const r3=&s1;
    int s2=123;

    return 0;
}