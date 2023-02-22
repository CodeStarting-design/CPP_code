#include<iostream>
#include<vector>
using namespace std;
typedef int arr[10]; // 此处是使用arr作为一个长度为10的int型数组的别名
using arrT=int[10];
int a[10]={0,1,2,3,4,5,6,7,8,9};
int b[10]={-1,1,2,3,4,5,6,7,8,9};
// 返回数组指针实现
int (*func1(int i))[10]{
    return (i)?&a:&b;
}
arr *func2(int i){
    return (i)?&a:&b;
}
arrT *func3(int i){
    return (i)?&a:&b;
}
auto func4(int i)->int(*)[10]{
    return (i)?&a:&b;
}
decltype(a) *func5(int i){
    return (i)?&a:&b;
}
int main(){
    vector<arr*> array_p;
    arr *p=func1(0);
    for(int i=0;i<10;i++)
    cout<<(*p)[i]<<" ";
    cout<<endl;
    for(auto &p1:*p)
    cout<<p1<<" ";
    cout<<endl;
    int *q=a;
    for(int i=0;i<10;i++)
    cout<<q[i]<<" ";
    cout<<endl;
    for(int i=0;i<10;i++)
    cout<<*(q++)<<" ";
    cout<<endl;
    array_p.push_back(func1(0));
    array_p.push_back(func2(1));
    array_p.push_back(func3(0));
    array_p.push_back(func4(1));
    array_p.push_back(func5(0));
    for(auto &array:array_p){
        for(int i=0;i<10;i++)
        cout<<(*array)[i]<<" ";
        cout<<endl;
    }

}