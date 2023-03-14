#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main(){
   int i=0;
   auto f=[i](const int j)->int { return i+j;};
   cout<<f(2)<<endl;
}