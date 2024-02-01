#include<iostream>
#include<vector>
using std::vector;
int removeElement(vector<int>& nums, int val) {
        int i=0,j=0,n=nums.size();
        for(;i<n;i++){
            if(nums[i]!=val){
                nums[j++]=nums[i];
            }
        }
        int res=j;
        for(;j<n;j++)
        nums.pop_back();
        return res;
    }
int main(){
    vector<int> nums={3,2,2,3};
    std::cout<<removeElement(nums,2);
    for(auto i:nums)
    std::cout<<i;
}