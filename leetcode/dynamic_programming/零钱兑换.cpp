#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using std::vector;
using std::min;
using std::cout;
using std::setw;
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                if(dp[j]!=-1){
                    if(dp[j-coins[i]]!=-1)
                        dp[j]=min(dp[j],dp[j-coins[i]]+1);
                }else{
                    if(dp[j-coins[i]]!=-1)
                        dp[j]=dp[j-coins[i]]+1;
                }
            }
            for(auto a:dp) cout<<setw(2)<<a<<",";
            cout<<std::endl;
        }
        return dp[amount];
    }
    int main(){
        vector<int> coins={1, 2, 5};
        cout<<coinChange(coins,11);
    }