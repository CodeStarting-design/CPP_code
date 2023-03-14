#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main(){
   auto f=[](const int i,const int j)->int { return i+j;};
   cout<<f(1,2)<<endl;
}