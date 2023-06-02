#include<iostream>
#include<vector>
using std::vector;
    int count=0;
    int tmp=0;
    void backTrack(vector<int>& nums,int target,int cur){
        if(cur==nums.size()){
            if(tmp==target) count++;
            return;
        }
        tmp+=nums[cur];
        backTrack(nums,target,cur+1);
        tmp-=nums[cur];
        tmp-=nums[cur];
        backTrack(nums,target,cur+1);
        tmp+=nums[cur];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        backTrack(nums,target,0);
        return count;
    }
    int main(){
        vector<int> nums={1,1,1,1,1};
        std::cout<<findTargetSumWays(nums,3);
    }