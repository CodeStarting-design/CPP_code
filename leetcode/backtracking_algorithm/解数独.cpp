#include<iostream>
#include<vector>
using std::vector;
    bool backtrack(int row,int col,vector<vector<char>>& board){
        if(row==board.size()){
            return true;
        }
        if(col==board.size()){ // row行完成填写
            if(backtrack(row+1,0,board)){
                return true;
            }
            return false;
        }
        if(board[row][col]!='.'){// 已填数字
            if(backtrack(row,col+1,board))
                return true;
            return false;
        }
        bool used[9]={false};
        for(int i=0;i<board[row].size();i++){ // 处理行
            if(board[row][i]!='.') used[board[row][i]-'1']=true;
        }
        for(int i=0;i<board.size();i++){ // 处理列
            if(board[i][col]!='.') used[board[i][col]-'1']=true;
        }
        // 处理粗线宫格
        for(int i=row/3*3;i<row/3*3+3;i++){
            for(int j=col/3*3;j<col/3*3+3;j++){
                if(board[i][j]!='.')
                    used[board[i][j]-'1']=true;
            }
        }
        for(int i=0;i<9;i++){
            if(!used[i]){
                board[row][col]='1'+i;
                if(backtrack(row,col+1,board)){
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(0,0,board);
    }
    int main(){
        vector<vector<char>> board={
            {'5','3','.','7','.','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'},
        };
        solveSudoku(board);
        for(auto &a:board){
            for(auto &c:a){
                std::cout<<c<<" ";
            }
            std::cout<<std::endl;
        }
    }

