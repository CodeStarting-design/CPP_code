#include<vector>
#include<queue>
#include<iostream>
using std::vector;
using std::queue;
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 图的拓扑排序，numCourses就是图的节点个数
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> link(numCourses);// 节点i的尾后节点
        for(auto &a:prerequisites){// 统计
            inDegree[a[0]]++;
            link[a[1]].push_back(a[0]);
        }
        queue<int> zero;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0) zero.push(i);
        }
        while(!zero.empty()){
            int n=zero.size();
            for(int i=0;i<n;i++){
                int tmp=zero.front();
                zero.pop();
                for(auto a:link[tmp]){
                    inDegree[a]--;
                    if(!inDegree[a])zero.push(a);
                }
            }
        }
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]) return false;
        }
        return true;
    }
    int main(){
        vector<vector<int>> pre={{1,0}};
        std::cout<<canFinish(2,pre);
    }