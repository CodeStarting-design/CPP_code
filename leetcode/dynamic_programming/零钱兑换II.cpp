#include<vector>
#include<iostream>
using std::vector;
    // int change(int amount, vector<int>& coins) {
    //     vector<int> dp(amount+1,0);
    //     for(int i=0;i*coins[0]<=amount;i++)
    //         dp[i*coins[0]]=1;
    //     for(auto a:dp) std::cout<<a<<",";
    //     std::cout<<std::endl;
    //     for(int i=1;i<coins.size();i++){
    //         for(int j=coins[i];j<=amount;j++){
    //             dp[j]=dp[j]+dp[j-coins[i]];
    //         }
    //         for(auto a:dp) std::cout<<a<<",";
    //         std::cout<<std::endl;
    //     }
    //     return dp.back();
    // }
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0]=1;
        for(auto a:dp) std::cout<<a<<",";
            std::cout<<std::endl;
        for(int j=1;j<=amount;j++){
            for(int i=0;i<coins.size();i++){
                dp[j]=j>=coins[i]?dp[j]+dp[j-coins[i]]:dp[j];
            }
            for(auto a:dp) std::cout<<a<<",";
            std::cout<<std::endl;
        }
        return dp.back();
    }
    int main(){
        vector<int> coins={1,2,5};
        std::cout<<change(5,coins);
    }