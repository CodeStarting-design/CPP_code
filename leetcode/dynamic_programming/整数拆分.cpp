#include<iostream>
#include<vector>
#include<algorithm>
using std::max;
using std::vector;
    int getDp(const vector<int> &dp,int i){
        int res=0,tmp;
        for(int j=1;j<=i/2;j++){
            tmp=max(dp[i-j]*dp[j],(i-j)*j);
            res=max(res,tmp);
        }
        return res;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        for(int i=2;i<=n;i++){
            dp[i]=getDp(dp,i);
        }
        return dp[n];
    }
    int main(){
        std::cout<<integerBreak(8)<<std::endl;
    }