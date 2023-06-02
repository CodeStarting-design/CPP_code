#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<utility>
using std::string;
using std::vector;
using std::abs;
using std::pair;
vector<vector<string>> res;
    vector<string> tmp;
    bool col[9]={false};
    vector<pair<int,int>> pos;
    bool isSlash(int i,int j){ // 第i行，第j列处的元素是否和前面的元素处于同一斜线
        if(pos.empty()) return false;
        for(auto &a:pos){
            if(abs(a.first-i)==abs(a.second-j)) return true;
        }
        return false;
    }
    void DFS(int cur,int n){ // 逐行放置
        if(cur==n){
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<n;i++){ // cur行位置的选取
            if(!col[i]&&!isSlash(cur,i)){ // 和前面的行，不在同一列，并且不在同一斜线
                col[i]=true;
                pos.push_back({cur,i});
                string s(n,'.');
                s[i]='Q';
                tmp.push_back(s);
                DFS(cur+1,n);
                tmp.pop_back();
                pos.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        DFS(0,n);
        return res;
    }
    int main(){
        solveNQueens(4);
        for(auto &a:res){
            for(auto &c:a){
                std::cout<<c<<" ";
            }
            std::cout<<std::endl;
        }
    }