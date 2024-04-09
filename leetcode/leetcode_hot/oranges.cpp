#include<vector>
#include<utility>
#include<iostream>
#include<queue>
using std::vector;
using std::pair;
using std::queue;

    bool DFS(vector<vector<int>>& grid,int i,int j){
        if(i<0||j<0||i>grid.size()-1||j>grid[0].size()-1||grid[i][j]==0||grid[i][j]==-1) return true;
        if(grid[i][j]==-2) return false;
        grid[i][j]=grid[i][j]==1?-1:-2;
        bool bottom=DFS(grid,i+1,j);
        bool top=DFS(grid,i-1,j);
        bool left=DFS(grid,i,j+1);
        bool right=DFS(grid,i,j-1);
        return grid[i][j]==-1&&bottom&&top&&left&&right; 
    }
int orangesRotting(vector<vector<int>>& grid) {
        // 先判断是否可能永远不会
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&DFS(grid,i,j)) return -1;
            }
        }
        // 寻找烂橘子加入队列  
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==-2||grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int res=0;
        while(!q.empty()){
            int qs=q.size();
            for(int i=0;i<qs;i++){
                pair<int,int> tmp=q.front();
                q.pop();
                int a=tmp.first,b=tmp.second;
                if(a>0&&(grid[a-1][b]==1||grid[a-1][b]==-1)){
                    q.push({a-1,b});
                    grid[a-1][b]=-2;
                }
                if(b>0&&(grid[a][b-1]==1||grid[a][b-1]==-1)){
                    q.push({a,b-1});
                    grid[a][b-1]=-2;
                }
                if(a<n-1&&(grid[a+1][b]==1||grid[a+1][b]==-1)){
                    q.push({a+1,b});
                    grid[a+1][b]=-2;
                }
                if(b<m-1&&(grid[a][b+1]==1||grid[a][b+1]==-1)){
                    q.push({a,b+1});
                    grid[a][b+1]=-2;
                }
            }
            if(!q.empty())
            res++;
        }
        return res;
    }

int main(){
    vector<vector<int>> grid={{2,1,1},{1,1,0},{0,1,1}};
    std::cout<<orangesRotting(grid);
}
