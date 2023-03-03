#include<iostream>
using namespace std;
class Y;
class X{
int a;
Y *p;
};
class Y{
    int b;
    X a;
};
int main(){
    X x;
    Y y;
}
