#include<iostream>
#include<vector>
#include<string>
using std::vector;
using std::string;
    bool ifsame(vector<int>& tmp){
        for(auto a:tmp){
            if(a!=0) return false;
        }
        return true;
    }
    // 此处的要求是两个单词中的字母有且仅有字母顺序不同
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.size()==1) {
            res.push_back(strs);
            return res;
        }
        int n=strs.size();
        vector<bool> flag(n,false); // 全部初始化为false
        for(int i=0;i<n;i++){
            if(flag[i]) continue;
            vector<int> map(26,0);// 用于统计的hash
            for(auto a:strs[i]) map[a-'a']++;
            vector<string> group={strs[i]};
            flag[i]=true;
            for(int j=i+1;j<n;j++){
                if(strs[i].size()!=strs[j].size()) continue; // 长度不同跳过
                vector<int>tmp=map;
                for(auto a:strs[j]) tmp[a-'a']--;
                if(ifsame(tmp)){
                    group.push_back(strs[j]);
                    flag[j]=true;
                }
            }
            res.push_back(group);
        }
        return res;
    }
int main(){
    vector<string> strs={"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res=groupAnagrams(strs);
}