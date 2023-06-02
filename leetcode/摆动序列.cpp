#include<vector>
#include<iostream>
#include<algorithm>
using std::vector;
using std::cout;
using std::max;
    int getWiggle(int start,vector<int>& nums){
        vector<int> tmp;
        tmp.push_back(nums[start]);
        for(int i=start+1;i<nums.size();i++){
            if(tmp.size()==1){
                if(nums[i]!=tmp.back()){
                    tmp.push_back(nums[i]);
                }
                continue;
            }else{
                if(((tmp[tmp.size()-1]-tmp[tmp.size()-2])*(tmp[tmp.size()-1]-nums[i]))<0){
                    tmp.push_back(nums[i]);
                }
            }
        }
        return tmp.size();
}
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1) return 1;
        if(nums.size()==2&&nums.front()!=nums.back()) return 2;
        int maxLen=0;
        for(int i=0;i<nums.size();i++){ // 分别作为起点
            if(maxLen>=nums.size()-i) break;
            maxLen=max(maxLen,getWiggle(i,nums));
        }
        return maxLen;
    }
    int main(){
        vector<int> nums={1,7,4,9,2,5};
        cout<<wiggleMaxLength(nums)<<std::endl;
    }