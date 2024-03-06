#include<vector>
#include<iostream>
#include<string>
using std::string;
using std::vector;
bool issame(vector<int>& v_s,vector<int>& v_p){
        for(int i=0;i<v_s.size();i++){
            if(v_s[i]!=v_p[i]) return false;
        }
        return true;
    }
    int getMap(string s ,int left,int right,vector<int>& v_p,vector<int>& v_s){
        vector<int> res(26,0);
        for(int i=left;i<=right;i++){
            if(v_p[s[i]-'a']){
                res[s[i]-'a']++;
            }else return i;
        }
        v_s=res;
        for(int i=0;i<26;i++){
            if(res[i]!=v_p[i]) return -1;
        }
        return -2;
    }
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),m=p.size();
        if(n<m) return {};
        vector<int> v_p(26,0);
        for(auto a:p) v_p[a-'a']++;
        vector<int> v_s;
        vector<int> res;
        int left=0,right=m-1;// 滑动窗口的两端点
        bool flag=false,success=false;
        while(right<n){
            if(flag){
                if(success){
                    if(s[left-1]==s[right]) {
                        success=true;
                        res.push_back(left);
                        left++,right++;
                    }
                    else{
                        if(v_p[s[right]-'a']){
                            success=false;
                            v_s[s[left-1]-'a']--;
                            v_s[s[right]-'a']++;
                            left++,right++;
                        }else{
                            flag=false;
                            left=right+1;
                            right=left+m-1;
                            success=false;
                        }
                    }
                }else{
                    if(v_p[s[right]-'a']){
                    v_s[s[left-1]-'a']--;
                    v_s[s[right]-'a']++;
                    if(issame(v_s,v_p)){
                        res.push_back(left);
                        success=true;
                    }
                    left++,right++;
                    }else{
                        flag=false;
                        left=right+1;
                        right=left+m-1;
                        success=false;
                    }
                }
            }else{ // 尚未统计
                int i=getMap(s,left,right,v_p,v_s);
                if(i==-1){
                    left++,right++;flag=true;
                }else if(i==-2){
                    res.push_back(left);
                    left++,right++;flag=true;success=true;
                }else{
                    left=i+1,right=left+m-1;
                }
            }
        }
        return res;
    }

int main(){
    string s="cbaebabacd";
    string p="abc";
    vector<int> res=findAnagrams(s,p);
}
