#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using std::setw;
using std::min;
using std::vector;
    int numSquares(int n) {
        vector<int> nums;
        for(int i=1;i*i<=n;i++){
            nums.push_back(i*i);
        }
        vector<int> dp(n+1,INT32_MAX);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
            for(int j=nums[i];j<=n;j++){
                if(dp[j-nums[i]]!=INT32_MAX){
                    dp[j]=min(dp[j],dp[j-nums[i]]+1);
                }
            }
            for(auto a:dp) std::cout<<setw(2)<<a<<",";
            std::cout<<std::endl;
        }
        return dp[n];
    }
    int main(){
        std::cout<<numSquares(13);
    }
