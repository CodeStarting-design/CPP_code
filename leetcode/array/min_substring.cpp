#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<unordered_set>
using std::unordered_set;
using std::pair;
using std::string;
using std::vector;
    int char2int(char a){
        if(a>='a'){
            return a-'a'+26;
        }else{
            return a-'A';
        }
    }
    bool is_cover(vector<int> t_num){
        for(auto i:t_num){
            if(i>0) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {// 解题的重点在于如何实现字符串的匹配 
        vector<int> t_num(52,0);// 单纯用来记录个数
        unordered_set<char> cset(t.begin(),t.end());// 构造相应的关键字hash
        for(auto a:t){
            t_num[char2int(a)]++;
        }
        int res_len=INT_MAX,start=0,end=0;
        int n=s.size();
        int tmp_len=INT_MAX;
        string res;
        while(end<n){
            while(!is_cover(t_num) && end<n){
                if(cset.find(s[end])!=cset.end()) // 是子串中的关键字
                    t_num[char2int(s[end])]--;
                end++;
            }//此处的end是后增的，所以此时的end实际上所指的窗口的后一位
            // 尝试减小滑动窗口
            while(is_cover(t_num)){
                tmp_len=end-start; 
                if(cset.find(s[start])!=cset.end()) // 是子串中的关键字
                    t_num[char2int(s[start])]++;
                start++;
            }
            // 在结束后，start-1所指的才是窗口的开头
            
            if(tmp_len<res_len){// 此处的比较一定需要是小于
                string tmp;
                for(int i=start-1;i<end;i++)
                    tmp+=s[i];
                res=tmp;
                res_len=tmp_len;
            }
        }
        return res;
    }
int main(){
    string s="a";
    string t="aa";
    string res=minWindow(s,t);
    std::cout<<res;
}