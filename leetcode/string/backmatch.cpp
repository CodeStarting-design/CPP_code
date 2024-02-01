#include<iostream>
#include<string>
using std::string;
int match(string m,string sub){
    int i=0,j=0;
    for(;i<m.size()&&j<sub.size();i++,j++){
        if(m[i]!=m[j]){
            i=i-j;
            j=-1;
        }
    }
    if(j==sub.size()) return i-j;
    return -1;
}
int KMP(string m,string sub){
    
}