#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using std::string;
using std::vector;
using std::max;

        void string2nums(string &s,int &n0,int &n1){
        for(auto a:s){
            if(a=='0') n0++;
            else n1++;
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp;
        dp.resize(m+1,vector<int>(n+1,0));
        for(int k=0;k<strs.size();k++){
            int n0=0,n1=0;
            string2nums(strs[k],n0,n1);
            for(int i=dp.size()-1;i>=n0;i--){
                for(int j=dp[0].size()-1;j>=n1;j--){
                    dp[i][j]=max(dp[i-n0][j-n1]+1,dp[i][j]);
                }
            }
            for(auto a:dp){
                for(auto c:a){
                    std::cout<<c<<" ";
                }
                std::cout<<std::endl;
            }
            std::cout<<std::endl;
        }
        return dp.back().back();
    }
    int main(){
        vector<string> strs={"10","1","0"};
        int m=1,n=1;
        std::cout<<findMaxForm(strs,m,n);
    }