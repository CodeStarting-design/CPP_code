#include<iostream>
using namespace std;
int static_fun(){
    static int i=0;
    return ++i;
}
int main(){
    for(int j=0;j<10;j++)
    cout<<static_fun()<<endl;
    return 0;
}