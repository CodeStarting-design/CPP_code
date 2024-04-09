#include<vector>
#include<iostream>
using std::vector;
int search(vector<int>& nums, int target) {
        int n=nums.size(),left=0,right=n-1,mid=0;
        int k=0;
        while(left<right){// 不断缩小原数组的长度直到只有一个元素
            mid=(left+right)/2;
            if(nums[mid]>nums[right]){
                left=mid+1;
            }
            if(nums[mid]<nums[left]){
                right=mid-1;
            }
            if(nums[mid]>=nums[left]&&nums[mid]<=nums[right]) break;
        }
        if(right<n-1&&nums[right]>nums[right+1]) k=right;
        if(left>0&&nums[left]<nums[left-1])k=left-1;
        // 按照k为划分进行查找
        left=0,right=k;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target) right=mid-1;
            else left=mid+1;
        }
        left=k+1,right=n-1;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
int main(){
    vector<int> nums={3,4,5,6,1,2};
    std::cout<<search(nums,2);
}