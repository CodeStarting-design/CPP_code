#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::sort;
vector<vector<int>> res;
    vector<int> tmp;
    void DFS(vector<int> &candidates,int target,int cur){
        if(target==0){
            res.push_back(tmp);
            return;
        }
        if(target<0||candidates[cur]>target) return;
        for(int i=cur;i<candidates.size();){
            tmp.push_back(candidates[i]);
            target-=candidates[i];
            DFS(candidates,target,i+1);
            target+=candidates[i];
            tmp.pop_back();
            for(int a=candidates[i];i<candidates.size()&&a==candidates[i];i++);
            if(i>=candidates.size()) return;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        DFS(candidates,target,0);
        return res;
    }

int main(){
    vector<int> candidates={10,1,2,7,6,1,5};
    int target=8;
    combinationSum2(candidates,target);
    for(auto a:res)
        for(auto c:a)
            std::cout<<c<<" ";
}