#include<vector>
#include<iostream>
#include<algorithm>
#include<limits.h>
using std::max;
using std::vector;
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 0;
        vector<vector<int>> dp(2,vector<int>(4,0));
        dp[0][0]-=prices[0];
        for(int i=1;i<n;i++){
            dp[1][0]=max(dp[0][0],max(dp[0][1]-prices[i],dp[0][3]-prices[i]));
            dp[1][1]=max(dp[0][1],dp[0][3]);
            dp[1][2]=dp[0][0]+prices[i];
            dp[1][3]=dp[0][2];
            dp[0]=dp[1];
        }
        return max(dp[1][0],max(dp[1][1],max(dp[1][2],dp[1][3])));
    }
    int main(){
        vector<int> prices={1,2,3,0,2};
        maxProfit(prices);
    }