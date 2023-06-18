#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using std::max;
using std::vector;
using std::setw;
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 0;
        vector<vector<int>> dp(n,vector<int>(5,0));
        dp[0][1]-=prices[0];
        dp[0][3]-=prices[0];
        for(int i=1;i<n;i++){
            dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1]);
            dp[i][2]=max(dp[i-1][1]+prices[i],dp[i-1][2]);
            dp[i][3]=max(dp[i-1][2]-prices[i],dp[i-1][3]);
            dp[i][4]=max(dp[i-1][3]+prices[i],dp[i-1][4]);
        }
        for(auto a:dp){
            for(auto c:a)
                std::cout<<setw(2)<<c<<" ,";
            std::cout<<std::endl;
        }
        return max(dp[n-1][0],max(dp[n-1][2],dp[n-1][4]));
    }
    int main(){
        vector<int> prices={3,3,5,0,0,3,1,4};
        std::cout<<maxProfit(prices);
    }
