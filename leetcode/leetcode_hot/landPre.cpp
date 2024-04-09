#include<iostream>
#include<vector>
using std::vector;
    int count=0;
    int DFS(vector<vector<int>>& grid,int i,int j){
        if(i<0||i>grid.size()-1||j<0||j>grid[0].size()-1||grid[i][j]==0) return 1;
        if(grid[i][j]==2) return 0;
        grid[i][j]=2;
        int left=DFS(grid,i-1,j);
        int right=DFS(grid,i+1,j);
        int top=DFS(grid,i,j-1);
        int bottom=DFS(grid,i,j+1);
        count+=left;
        count+=right;
        count+=top;
        count+=bottom;
        return 0;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        // 深度优先
        int n=grid.size(),m=grid[0].size();
        bool flag=true;
        for(int i=0;i<n&&flag;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1){
                    DFS(grid,i,j);
                    flag=false;
                    break;
                }
        return count;
    }

int main(){
    vector<vector<int>> grid={
        {0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}
        };
    std::cout<<islandPerimeter(grid);
}