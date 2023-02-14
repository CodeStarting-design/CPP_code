#include<iostream>
using namespace std;
using int_array=int[4];
int main(){
    int ia[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    for(int_array (&p):ia){
        for(int q:p)
        cout<<q<<" ";
        cout<<endl;
    }
    for(int_array *p1=ia;p1!=end(ia);p1++){
        for(int *q1 = *p1;q1!=end(*p1);q1++)
        cout<<*q1<<" ";
    cout<<endl;
    }
    for(auto &p2:ia){
        for(auto q2:p2)
        cout<<q2<<" ";
        cout<<endl;
    }
    return 0;
}