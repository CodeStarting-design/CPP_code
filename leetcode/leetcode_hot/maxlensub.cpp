#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;
 int lengthOfLongestSubstring(string s) {
        //滑动窗口实现，记录窗口的最大长度，使用hash记录窗口内的元素
        if(s.size()==0) return 0;
        int res=1,left=0,right=1;
        unordered_map<char,int> mp;
        mp[s[0]]=0;
        while(right<s.size()){
            // 尝试扩大窗口
            if(mp.count(s[right])){
                // 存在冲突
                int index=mp[s[right]];
                for(int i=left;i<=index;i++){
                    mp.erase(s[i]);
                }
                left=index+1;
                mp[s[right]]=right;
                right++;
            }else{// 不存在冲突
                mp[s[right]]=right;
                right++;
                res=max(res,right-left);
            }
        }
        return res;
    }
    int main(){
        string s="abcabcbb";
        cout<<lengthOfLongestSubstring(s);
    }