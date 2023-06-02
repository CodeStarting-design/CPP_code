#include<iostream>
#include<vector>
using std::vector;
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,0);
        dp[0]=1;
        for(int j=1;j<=target;j++){
            for(int i=0;i<nums.size();i++){
                dp[j]=j>=nums[i]?dp[j]+dp[j-nums[i]]:dp[j];
            }
            for(auto a:dp) std::cout<<a<<",";
            std::cout<<std::endl;
        }
        return dp[target];
    }
    int main(){
        vector<int> nums={1,2,3};
        std::cout<<combinationSum4(nums,4);
    }