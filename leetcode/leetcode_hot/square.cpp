#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using std::sqrt;
using std::min;
using std::vector;
bool isSquare(int n){
        return ((int)sqrt(n)*(int)sqrt(n))==n;
    }
    int numSquares(int n) {
        vector<int> dp(n,n);
        for(int i=0;i<n;i++){
            if(isSquare(i+1)) dp[i]=1;
            else{
                for(int j=1;j<=(i+1)/2;j++){
                    dp[i]=min(dp[i],dp[j-1]+dp[i-j]);
                }
            } 
        }
        return dp[n-1];
    }

int main(){
    std::cout<<numSquares(12);
}