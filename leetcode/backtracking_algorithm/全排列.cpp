#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::cout;
using std::swap;
        vector<vector<int>> res;
    vector<int> tmp;
    void DFS(vector<int>& nums,int first){
        if(first==nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=first;i<nums.size();i++){
            tmp.push_back(nums[i]);
            swap(nums[i],nums[first]);
            DFS(nums,i+1);
            swap(nums[i],nums[first]);
            tmp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        DFS(nums,0);
        return res;
    }
    int main(){
        vector<int> nums={1,2,3};
        permute(nums);
        for(auto &a:res){
            for(auto &c:a)
                cout<<c<<" ";
            cout<<std::endl;
        }       
    }