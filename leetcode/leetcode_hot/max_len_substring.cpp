#include<map>
#include<string>
#include<iostream>
#include<unordered_map>
#include<algorithm>
using std::unordered_map;
using std::string;
using std::max;
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_map<char,int> s_map;
        int res=0,n=s.size();
        int left=-1,right=0;
        while(right<n){
            if(s_map.find(s[right])==s_map.end()){
                res=max(res,right-left);
                s_map[s[right]]=right;
            }else{
                // 重复也存在两种，起点前重复和起点后重复
                if(s_map[s[right]]<left){
                    res=max(res,right-left);
                    s_map[s[right]]=right;// 更新
                }else{
                    left=s_map[s[right]];// 修改起点
                    s_map[s[right]]=right;
                }
            }
            right++;
        }
        return res;
    }
int main(){
    string s="asga8udgisafdausdauigasiu";
    std::cout<<lengthOfLongestSubstring(s);
}