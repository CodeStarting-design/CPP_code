#include<vector>
#include<string>
#include<iostream>
using namespace std;

    int longestValidParentheses(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int res=0;
        // 对于i>j的情形，全部初始化为0
        for(int i=n-1;i>0;i--){
            for(int j=0;j<i;j++){
                dp[i][j]=0;
            }
        }
        for(int i=n-2;i>-1;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]=='('&&s[j]==')'){
                    if(dp[i+1][j-1]==-1){
                        dp[i][j]=max(dp[i][j],-1);
                    }else{
                        dp[i][j]=max(dp[i+1][j-1]+2,dp[i][j]);
                    }
                }
                if(s[i]=='('&&s[i+1]==')'&&i<n-2){
                    if(dp[i+2][j]==-1){
                        dp[i][j]=max(dp[i][j],-1);
                    }else{
                        dp[i][j]=max(dp[i+2][j]+2,dp[i][j]);
                    }
                }
                if(s[j-1]=='('&&s[j]==')'&&j>1){
                    if(dp[i][j-2]==-1){
                        dp[i][j]=max(dp[i][j],-1);
                    }else{
                        dp[i][j]=max(dp[i][j-2]+2,dp[i][j]);
                    }
                }
                res=max(res,dp[i][j]);
            }
        }
        return res;
    }
int main(){
    string s=")(((((()())()()))()(()))(";
    cout<<longestValidParentheses(s);
}