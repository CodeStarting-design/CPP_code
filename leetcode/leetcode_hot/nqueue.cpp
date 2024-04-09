#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using std::min;
using std::max;
using std::vector;
using std::string;
    vector<vector<string>> res;
    vector<string> tmp;
    vector<bool> pos;
        void DFS(int cur,int n){
        if(cur==n){
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<n;i++){
            if(!pos[i]){
                bool flag=false;
                for(int j=cur;j>0;j--){
                    flag=flag||(i-j>-1?pos[i-j]:false)||(i+j<n?pos[i+j]:false);
                    if(flag) break;
                }
                if(!flag){
                    string s= string(n,'.');
                    s[i]='Q';
                    pos[i]=true;
                    tmp.push_back(s);
                    DFS(cur+1,n);
                    tmp.pop_back();
                    pos[i]=false;
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        pos.resize(n);
        DFS(0,n);
        return res;
    }
    
int main(){
    solveNQueens(4);
    for(auto &a:res){
        for(auto c:a){
            std::cout<<c<<" ";
        }
    }
}