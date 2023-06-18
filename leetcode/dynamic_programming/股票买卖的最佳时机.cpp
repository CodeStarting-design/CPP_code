#include<iostream>
#include<vector>
#include<algorithm>
using std::max;
using std::vector;
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 0;
        vector<int> dp(n+1,0);
        int res=0;
        for(int i=n-1;i>0;i--){
            dp[i]=max(dp[i+1]+(prices[i]-prices[i-1]),0);
            std::cout<<dp[i]<<",";
            res=max(res,dp[i]);
        }
        return res;
    }
    int main(){
        vector<int> prices={7,1,5,3,6,4};
        std::cout<<maxProfit(prices);
    }
