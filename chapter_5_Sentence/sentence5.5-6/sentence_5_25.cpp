#include<iostream>
#include<stdexcept>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b;
    try{
        // if(b==0) 
        // throw runtime_error("divisor by 0");
        // else 
        c=a/b;
        cout<<c<<endl;
    }catch(runtime_error err){
        cout<<err.what()<<endl;
    }
    return 0;
}