#include<vector>
#include<iostream>
using std::vector;
    vector<vector<int>> res;
    vector<int> tmp;
    int sum=0;
    void backSelect(vector<int>& candidates,int cur,int target){
        if(sum==target){
            res.push_back(tmp);
            return ;
        }
        if(cur>=candidates.size()||sum>target) return;
        sum+=candidates[cur];
        tmp.push_back(candidates[cur]);
        backSelect(candidates,cur,target);
        tmp.pop_back();
        sum-=candidates[cur];
        backSelect(candidates,cur+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backSelect(candidates,0,target);
        return res;
    }
    int main(){
        vector<int> candidates={2,3,6,7};
        combinationSum(candidates,7);
        for(auto &a:res){
            for(auto c:a){
                std::cout<<c<<" ";
            }
        }
    }
    