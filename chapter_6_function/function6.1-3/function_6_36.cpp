#include<iostream>
#include<string>
using namespace std;
string array[]={"1","2","3","4","5","6","7","8","9","10"};
string (&func(int i))[10]{
    return array;
}
int main(){
for(auto &str:array)
cout<<str<<" ";
cout<<endl;
string (&s) [10]=func(10);
for(auto &str:s)
cout<<str<<" ";
cout<<endl;
for(int i=0;i<10;cout<<s[i++]<<" ");
cout<<endl;
}