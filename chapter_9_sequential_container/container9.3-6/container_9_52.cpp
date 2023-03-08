/* ************************************************************************
> File Name:     container_9_52.cpp
> Author:        mark
> Created Time:  2023年03月08日 星期三 09时04分10秒
> Description:   
 ************************************************************************/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string expr;
    while(cin>>expr){
        stack<char> s;
        bool flag=false;
        for(auto a:expr){
            if(a=='('){
                flag=true;
                continue;
            }else if(a==')') flag=false;
            if(flag) s.push(a);
        }
        string sub;
        while(!s.empty()){
            sub+=s.top();
            s.pop();
        }
        expr.replace(expr.find('('),sub.size(),sub);
        cout<<expr<<endl;
    }
}
