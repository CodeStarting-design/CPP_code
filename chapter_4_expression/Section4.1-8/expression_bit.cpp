#include<iostream>
using namespace std ;
int main(){
    int n=8;
    n<<2;
    cout<<n<<endl;
    cout<<(n<<2)<<endl;
    ~n;
    cout<<n<<endl;
    cout<<(~n)<<endl;
    cout<<(~'q'<<6)<<endl;
    return 0;
}