#include<iostream>
#include<vector>
using std::vector;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix.front().size();
        vector<int> res;
        int start_i=0,start_j=0;
        while(n>1&&m>1){
            int i=start_i,j=start_j;
            // 向右
            for(;j<start_j+n-1;j++)
                res.push_back(matrix[i][j]);
            // 向下
            for(;i<start_i+m-1;i++)
                res.push_back(matrix[i][j]);
            // 向左
            for(;j>start_j;j--)
                res.push_back(matrix[i][j]);
            for(;i>start_i;i--)
                res.push_back(matrix[i][j]);
            start_i++,start_j++;
            n-=2,m-=2;
        }
        if(n==0||m==0) return res;
        if(n==1){// 列不够了，向下加入
            int j=start_j;
            for(int i=start_i;i<start_i+m;i++)
                res.push_back(matrix[i][j]);
        }else if(m==1){// 行不够了向右加入
            int i=start_i;
            for(int j=start_j;j<start_j+n;j++)
                res.push_back(matrix[i][j]);
        }
        return res;
    }

int main(){
    vector<vector<int>> matrix={
        {1,2,3,4},{5,6,7,8},{9,10,11,12}
    };
    vector<int> res = spiralOrder(matrix);
}