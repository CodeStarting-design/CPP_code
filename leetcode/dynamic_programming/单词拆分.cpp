#include<vector>
#include<iostream>
#include<string>
using std::vector;
using std::string;
    bool match(string& s,int j,string& word){
        for(int i=0;i<word.size();i++){
            if(word[i]!=s[j-word.size()+1+i])
                return false;
        }
        return true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for(int j=1;j<=s.size();j++){
            for(int i=0;i<wordDict.size();i++){
                if(j>=wordDict[i].size()){
                    dp[j]=dp[j]||(dp[j-wordDict[i].size()]&&match(s,j-1,wordDict[i]));
                }
            }
            for(auto a:dp) std::cout<<a<<",";
            std::cout<<std::endl;
        }
        return dp[s.size()];
    }
    int main(){
        string s = "applepenapple";
        vector<string>wordDict = {"apple","pen"};
        wordBreak(s,wordDict);
    }