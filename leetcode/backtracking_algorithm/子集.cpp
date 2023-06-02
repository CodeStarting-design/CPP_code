#include<vector>
#include<iostream>
using std::vector;
using std::cout;
        vector<vector<int>> res;
    vector<int> tmp;
    void DFS(vector<int>& nums,int cur){
        if(cur==nums.size()){
            return;
        }
        for(int i=cur;i<nums.size();i++){
            tmp.push_back(nums[i]);
            res.push_back(tmp);
            DFS(nums,i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back({});
        for(int i=0;i<nums.size();i++){
            tmp.clear();
            tmp.push_back(nums[i]);
            res.push_back(tmp);
            DFS(nums,i+1);
        }
        return res;
    }
    int main(){
        vector<int> nums={1,2,3};
        subsets(nums);
        for(auto &a:res){
            for(auto &c:a)
                cout<<c<<" ";
            cout<<std::endl;
        }
    }