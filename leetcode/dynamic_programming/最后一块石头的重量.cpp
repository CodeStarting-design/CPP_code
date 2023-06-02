#include<iostream>
#include<vector>
using std::vector;
 int lastStoneWeightII(vector<int>& stones) {
        if(stones.size()==1) return stones.front();
        int sum=0;
        for(auto a:stones) sum+=a;
        vector<bool> dp(sum/2+1,false);
        dp[0]=true;
        if(stones[0]<=sum/2) dp[stones[0]]=true;
        for(int i=1;i<stones.size();i++){
            for(int  j=dp.size()-1;j>=stones[i];j--){
                dp[j]=dp[j]||dp[j-stones[i]];
            }
            for(auto a:dp) std::cout<<a<<",";
            std::cout<<std::endl;
        }
        int i;
        for(i=dp.size()-1;!dp[i];i--);
        return sum-(2*i);
    }
int main(){
    vector<int> stones={2,7,4,1,8,1};
    std::cout<<lastStoneWeightII(stones);
}