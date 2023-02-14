#include<iostream>
using namespace std;
int main(){
    int a[10],*p=a;
    cout<<sizeof a/ sizeof *a<<endl;
    cout<<sizeof p/ sizeof *p<<endl;
    return 0;
}