#include<iostream>
#include<vector>
#include<utility>
using std::pair;
using std::vector;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
    vector<pair<int,int>> s;
    int *pre=nullptr,count=0;
    void DFS(TreeNode* root){
        if(root){
            DFS(root->left);
            if(pre){
                if(root->val==*pre) count++;
                else{
                    pair<int,int> node=s.back();
                    if(count==node.second){
                        s.push_back({*pre,count});
                    }else if(count>node.second){
                        while(!s.empty()) s.pop_back();
                        s.push_back({*pre,count});
                    }
                    pre=&root->val;
                    count=1;
                }
            }else{
                pre=&root->val;
                count=1;
            }
            DFS(root->right);
        }
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        DFS(root);
        for(int i=0;i<s.size();i++)
            res.push_back(s[i].first);
        return res;
    }
int main(){
    TreeNode* root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(2);
    vector<int> res=findMode(root);
    for(auto a:res)
        std::cout<<a<<" ";
}