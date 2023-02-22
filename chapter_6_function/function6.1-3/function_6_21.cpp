#include<iostream>
using namespace std;
int find_max(int i,const int *j){
   if(i>*j){
    return i;
   }else return *j;
}
void exchange(int *i,int *j){
    int tmp=*i;
    *i=*j;
    *j=tmp;      
}
void print(int &i,int *j,const int len){
    cin>>i;
    for(int k=0;k<len;k++)
    cin>>j[k];
}
void print(const int ia[10]){
    for(size_t i=0;i!=10;i++)
    cout<<ia[i]<<endl;
}
int main(){
    int i=1,j=10,*p=&j,*q=&i;
    cout<<find_max(i,p)<<endl;
    exchange(q,p);
    cout<<i<<" "<<j<<endl;
    int arr[10]={1,2,3,4,5};
    print(i,arr,10);
    for(const auto &a:arr)
    cout<<a<<" ";
    print(arr);
    return 0;
}