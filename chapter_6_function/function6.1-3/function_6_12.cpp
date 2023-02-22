#include<iostream>
using namespace std;
void exchange(int &i,int &j){
    int tmp=i;
    i=j;j=tmp;
}
int main(){
    int i=1,j=0;
    exchange(i,j);
    cout<<i<<j<<endl;
    return 0;
}