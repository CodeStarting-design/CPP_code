#include<iostream>
#include<vector>
using std::vector;
using std::cout;
    vector<vector<int>> res;
    vector<int> tmp;
    bool used[8]={false}; // 记录那些位置的元素被使用
    void DFS(vector<int>& nums,int cur){
        if(cur==nums.size()){
            res.push_back(tmp);
        }
        int curUsed[21]={false}; // 记录当前层那些元素值被使用了
        for(int i=0;i<nums.size();i++){
            if(!used[i]&&!curUsed[nums[i]+10]){ // 在前层和当前层都没有使用过
                used[i]=true; // 标记使用
                tmp.push_back(nums[i]);
                curUsed[nums[i]+10]=true;
                DFS(nums,cur+1);
                tmp.pop_back();
                used[i]=false;
            }
        }   
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        DFS(nums,0);
        return res;
    }
    int main(){
        vector<int>nums ={1,2,1};
        permuteUnique(nums);
        for(auto &a:res){
            for(auto &c:a){
                cout<<c<<" ";
            }
            cout<<std::endl;
        }
    }