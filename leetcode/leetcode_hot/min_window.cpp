#include<unordered_map>
#include<string>
#include<iostream>
#include<limits.h>
using std::unordered_map;
using std::string;
string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        string res;
        if(n<m) return res;
        unordered_map<char,int> need,window;
        int valid=0,m_len=n;
        for(auto a:t) need[a]++;
        int left=0,right=INT_MAX;
        while(right<n){
            char a=s[right];
            right++;
            if(need.count(a)){
                window[a]++;
                if(window[a]==need[a]) valid++;
            }
            while(valid==need.size()){// 尝试缩短
                if(m_len>right-left){
                    res=s.substr(left,right-left);
                    m_len=right-left;
                }
                char c =s[left];
                left++;
                if(need.count(c)){
                    if(window[c]==need[c]) valid--;
                    window[c]--;
                }
            }
        }
        return res;

    }
int main(){
    string s="a",t="a";
    std::cout<<minWindow(s,t);
}