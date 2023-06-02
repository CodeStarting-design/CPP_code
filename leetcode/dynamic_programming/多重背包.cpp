#include<iostream>
#include<vector>
#include<algorithm>
using std::max;
using std::vector;
int mutil_pack(int v, vector<int>& nums,vector<int>& value,vector<int>& weight){
    // 首先将多重背包展开为0/1背包
    vector<int> weights;
    vector<int> values;
    for(int i=0;i<weight.size();i++){
        for(int j=0;j<nums[i];j++){
            weights.push_back(weight[i]);
            values.push_back(value[i]);
        }
    }
    vector<int> dp(v+1,0);
    for(int i=0;i<weights.size();i++){
        for(int j=v;j>=weights[i];j++){
            dp[j]=max(dp[j],dp[j-weights[i]]+values[i]);
        }
    }
    return dp[v];
}

int mutil_pack2(int v,vector<int>& nums,vector<int>& value,vector<int>& weight){
    vector<int> dp(v+1,0);
    for(int i=0;i<weight.size();i++){
        for(int j=v;j>=weight[i];j--){
            for(int k=1;k<=nums[i]&&j-k*weight[i]>=0;k++){
                dp[j]=max(dp[j],dp[j-k*weight[i]]+(k*value[i]));
            }
        }
    }
    return dp[v];
}

int main(){
    
}