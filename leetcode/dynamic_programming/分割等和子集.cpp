#include<iostream>
#include<vector>
using std::vector;
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &a:nums) sum+=a;
        if(sum%2||nums.size()==1) return false;
        vector<bool> dp(sum/2+1,false);
        dp[0]=true;
        if(nums[0]<=sum/2) dp[nums[0]]=true;
        for(int i=1;i<nums.size();i++){
            for(int j=dp.size()-1;j>=nums[i];j--){
                dp[j]=dp[j]||dp[j-nums[i]];
            }
            for(auto a:dp) std::cout<<a<<",";
            std::cout<<std::endl;
            if(dp.back()==true) break;
        }
        return dp.back();        
    }
    int main(){
        vector<int> nums={1,5,11,5};
        std::cout<<canPartition(nums);
    }