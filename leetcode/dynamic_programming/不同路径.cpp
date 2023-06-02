#include<iostream>
#include<vector>
using std::vector;
using std::cout;
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        dp.resize(m,vector<int>(n));
        // 初始化第一行和第一列
        for(int i=1;i<n;i++)
            dp[0][i]=1;
        for(int i=1;i<m;i++)
            dp[i][0]=1;
        // 递推动态规划数组
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    int main(){
        cout<<uniquePaths(3,7);
    }