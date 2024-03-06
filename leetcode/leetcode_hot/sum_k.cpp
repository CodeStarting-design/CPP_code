#include<vector>
#include<unordered_map>
#include<iostream>
using std::vector;
using std::unordered_map;
int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),res=0;
        int sum=0;
        unordered_map<int,int> sum_map;
        sum_map[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum_map.find(sum-k)!=sum_map.end()){
                res+=sum_map[sum-k];
            }
            sum_map[sum]++;
        }
        return res;
    }
int main(){
    vector<int>nums={1,1,1};
    std::cout<<subarraySum(nums,2);
}