#include<vector>
#include<iostream>
using std::vector;
vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        int n=nums.size(),left=0,right=n-1,mid=0;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target) break;
            if(nums[mid]>target) right=mid-1;
            else left=mid+1;
        }
        if(left<=right){
            int i=mid,j=mid,pre_i=i,pre_j=j;
            while(nums[i]==target||nums[j]==target){
                i=i>0&&nums[i-1]==target?i-1:i;
                j=j<n-1&&nums[j+1]==target?j+1:j;
                if(pre_i==i&&pre_j==j) break;
                pre_i=i,pre_j=j;
            }
            res.front()=i,res.back()=j;
            
        }
        return res;
    }
    int main(){
        vector<int> nums={5,7,7,8,8,10};
        vector<int> res=searchRange(nums,8);
        std::cout<<res.front()<<" "<< res.back();
    }