#include<vector>
#include<iostream>
#include<unordered_set>
#include<algorithm>
using std::unordered_set;
using std::vector;
using std::cout;
using std::sort;

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // 此处排序的意义不仅仅在于保证每一次选中的都不是重复
        // 基于有序序列解决上述问题就会简单很多
        vector<vector<int>> res;
        // 双指针解决该问题，一个指针位于头部，一个位于尾部
        int left=0,right=nums.size()-1;
        while(left<right){// 
            int i=nums[left],k=nums[right];
            if(i+k>0){
                for(int mid=left+1;mid<right;mid++){
                    if(nums[mid]+i+k==0){
                        res.push_back({i,nums[mid],k});
                        break;
                    }
                }
                for(;left<right&&nums[left]==i;left++);
            }else{
                for(int mid=right-1;mid>left;mid--){
                    if(nums[mid]+i+k==0){
                        res.push_back({i,nums[mid],k});
                        break;
                    }
                }
                for(;right>left&&nums[right]==k;right--);
            }
        }
        return res;
    }
int main(){
    vector<int>nums={-1,0,1,2,-1,-4};
    vector<vector<int>> res=threeSum(nums);
}