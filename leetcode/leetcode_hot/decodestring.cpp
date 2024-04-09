#include<string>
#include<iostream>
using std::string;
    string decodeString(string s) {
        string res;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]>='a'&&s[i]<='z'){
                res.push_back(s[i]);
            }else{
                if(s[i]>='1'&&s[i]<='9'){
                    string num;
                    int j=i;
                    for(;j<n&&s[j]>='0'&&s[j]<='9';j++) num.push_back(s[j]);
                    int len=stoi(num);
                    //处理后续
                    int k=j+1;
                    string le;
                    for(;k<n&&s[k]!=']';k++) le.push_back(s[k]);
                    for(int l=0;l<len;l++) res+=le;
                    i=k;
                }
            }
        }
        return res;
    }
int main(){
    string s="3[a]2[bc]";
    std::cout<<decodeString(s)<<std::endl;
}