#include<iostream>
#include<vector>
using namespace std;
int funcDecl(int i,int j){
    return i;
}
int funcPlus(int i,int j){
    return i+j;
}
int minor(int i,int j){
    return i-j;
}
int multiply(int i,int j){
    return i*j;
}
int funcDivide(int i,int j){
    return j==0?j:i/j;
}
int arrayParameter(int a[10]){
    cout<<a[1]<<endl;
    return a[1];
}
using func=int (int ,int);
int main(){
    vector<func*> vec;
    vec.push_back(funcDecl);
    vector<int (*)(int ,int)>vec2;
    vec2.push_back(funcDecl);
    vec2.push_back(multiply);
    vec.push_back(minor);
    vec.push_back(funcPlus);
    vec.push_back(funcDivide);
    vec.push_back(multiply);
    for(auto &a:vec)
    cout<<a(1,2)<<endl;
    int arr[10]={1,2};
    arrayParameter(arr);
} 