#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using std::max;
using std::vector;
using std::setw;    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n<=1) return 0;
        int d=2*k+1;
        vector<vector<int>> dp(n,vector<int>(d,0));
        for(int i=1;i<d;i+=2){
            dp[0][i]-=prices[0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<d;j++){
                if(j%2){ // 奇数
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]-prices[i]);
                }else{
                    dp[i][j]=max(dp[i-1][j-1]+prices[i],dp[i-1][j]);
                }
            }
            for(auto a:dp){
                for(auto c:a){
                    std::cout<<setw(2)<<c<<",";
                }
                std::cout<<std::endl;
            }
        }
        return dp[n-1][d-1];
    }
    int main(){
        vector<int> prices={2,4,1};
        int k=2;
        maxProfit(k,prices);
    }