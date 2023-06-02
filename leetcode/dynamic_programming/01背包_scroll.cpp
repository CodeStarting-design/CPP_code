#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::max;
int backpack01(vector<int>& weight,vector<int>& value,int w){
    int n=weight.size();
    vector<int> dp(w+1,0);
    for(int i=weight[0];i<=w;i++)
        dp[i]=value[0];
    for(int i=1;i<n;i++){
        for(int j=w;j>=weight[i];j--){
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    return dp[w];
}
int main(){
    vector<int> weight={1,3,4};
    vector<int> value={15,20,30};
    std::cout<<backpack01(weight,value,4);
}