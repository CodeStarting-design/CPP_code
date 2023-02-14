#include<iostream>
using namespace std;
int main(){
    int i=42;
    const int &r1=i;
    const int &r2=42;
    return 0;
}