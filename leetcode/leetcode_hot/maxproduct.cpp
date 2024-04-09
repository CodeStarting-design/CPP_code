#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int maxProduct(vector<int>& nums) {
        vector<pair<int,int>> dp(nums.size(),{0,0});
        int res=nums[0];
        if(nums[0]>0){
            dp[0].first=nums[0];
        }
        if(nums[0]<0){
            dp[0].first=nums[0];
            dp[0].second=nums[0];
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                if(dp[i-1].first>0 && dp[i-1].second<0){
                    dp[i].first=dp[i-1].second*nums[i],dp[i].second=dp[i-1].first*nums[i];
                }else if(dp[i-1].first>0 && dp[i-1].second==0){
                    dp[i].first=nums[i],dp[i].second=dp[i-1].first*nums[i];
                }else if(dp[i-1].first==0 && dp[i-1].second==0){
                    dp[i].first=nums[i],dp[i].second=nums[i];
                }
                else if(dp[i-1].first<0){
                    dp[i].first=dp[i-1].second*nums[i],dp[i].second=0;
                }
            }
            if(nums[i]==0){
                dp[i].first=0,dp[i].second=0;
            }
            if(nums[i]>0){
                if(dp[i-1].first>0){
                    dp[i].first=nums[i]*dp[i-1].first;
                    dp[i].second=nums[i]*dp[i-1].second;
                }
                if(dp[i-1].first==0){
                    dp[i].first=nums[i],dp[i].second=0;
                }
                if(dp[i-1].first<0){
                    dp[i].first=nums[i],dp[i].second=nums[i]*dp[i-1].second;
                }
            }
            res=max(dp[i].first,res);
        }
        return res;
    }
int main(){
    vector<int> nums={0,2};
    cout<<maxProduct(nums)<<endl;
}