#include<iostream>
#include<stack>
#include<string>
using namespace std;
    string removeDuplicates(string s) {
        stack<char> s1;
        int i=0,n=s.size();
        for(;i<n;i++){
            if(s1.empty()||s1.top()!=s[i])
            s1.push(s[i]);
            else s1.pop();
        }
        if(s1.empty()) return "";
        n=s1.size();
        for(int j=n-1;j>=0;--j){
            s[j]=s1.top();
            s1.pop();
        }
        s.resize(n);
        return s;
    }
int main(){
    string a="abbaca";
    string res=removeDuplicates(a);
    cout<<res<<endl;
}