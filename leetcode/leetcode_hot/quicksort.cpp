#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::swap;
int part(vector<int>& nums,int start,int end){// 实现一个划分函数 确定一个元素的位置
    int mid=nums[start];
    while(start<end){
        while(start<end && nums[end]>=mid) end--;
        nums[start]=nums[end];
        while(start<end && nums[start]<mid) start++;
        nums[end]=nums[start];
    }
    nums[start]=mid;
    return start;
}
void QuickSort(vector<int>& nums,int low,int high){
    if(low<high){
        int i=part(nums,low,high);
        QuickSort(nums,low,i-1);
        QuickSort(nums,i+1,high);
    }
}
int main(){
    vector<int> nums={11,2,445,2,45,61,2,3,46,76,89,3,4,6,7};
    QuickSort(nums,0,nums.size()-1);
    for(auto a:nums) std::cout<<a<<" ";
}
