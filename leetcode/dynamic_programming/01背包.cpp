#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::max;
int backpack01(vector<int>& weight,vector<int>& value,int w){
    int n=weight.size();
    vector<vector<int>> dp;
    dp.resize(n,vector<int>(w+1,0));
    for(int i=weight[0];i<=w;i++){ // 直接从第一个物品的容量开始
        dp[0][i]=value[0];
    }
    for(int i=1;i<n;i++){ // 总计n行
        for(int j=1;j<=w;j++){
            if(j>=weight[i]){ // 能够放下
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n-1][w];
}
int main(){
    vector<int> weight={1,3,4};
    vector<int> value={15,20,30};
    std::cout<<backpack01(weight,value,4);
}