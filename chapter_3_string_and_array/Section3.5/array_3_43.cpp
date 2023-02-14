#include<iostream>
using namespace std;
int main(){
    int ia[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    for(int (&a)[4]:ia)
    {
    for(int &b:a)
    {
    cout<<b<<" ";
    }
    cout<<endl;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++)
        cout<<ia[i][j]<<" ";
    cout<<endl;
    }
    for(int (*p)[4]=ia;p!=end(ia);p++){
        for(int *q = *p;q!=end(*p);q++)
        cout<<*q<<" ";
    cout<<endl;
    }

    return 0;
}