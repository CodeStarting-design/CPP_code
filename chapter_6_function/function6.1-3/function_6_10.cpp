#include<iostream>
using namespace std;
void exchange(int *p,int *q){
    int tmp=*p;
    *p=*q;
    *q=tmp;
}
int main(){
    int i=0,j=1,*pi=&i,*pj=&j;
    exchange(pi,pj);
    cout<<i<<j<<endl;
    return 0;
}