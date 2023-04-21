#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using std::vector;
using std::min;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> s,p_ancestor,q_ancestor;
        TreeNode *node=root,*pre=nullptr;
        bool q_flag=false,p_flag=false;
        while(node||!s.empty()){
            if(node){
                s.push_back(node);
                if(node==q){
                    for(auto &a:s)
                        q_ancestor.push_back(a);
                    if(p_flag) break;
                    else q_flag=true;
                }
                if(node==p){
                    for(auto &a:s)
                        p_ancestor.push_back(a);
                    if(q_flag) break;
                    else p_flag=true;
                }
                node=node->left;
            }
            else{
                TreeNode* node1=s.back();
                if(node1->right&&node1->right!=pre){
                    node=node1->right;
                }else{
                    s.pop_back();
                    pre=node1;
                }
            }
        }
        int i;
        for(i=0;i<min(p_ancestor.size(),q_ancestor.size());i++){
            if(p_ancestor[i]!=q_ancestor[i]) break;
        }
        if(i<min(p_ancestor.size(),q_ancestor.size())){
            return p_ancestor[i];
        }else{
            return p_ancestor.size()>q_ancestor.size()?q_ancestor.back():p_ancestor.back();
        }
    }
int main(){
    vector<int> tree={3,5,1,6,2,0,8,-1,-1,7,4};
    int index=0;
    queue<TreeNode*> q;
    if(tree.empty()) return 0;
    TreeNode *root=new TreeNode(tree[index++]);
    q.push(root);
    while(!q.empty()&&index<tree.size()){
        TreeNode *node=q.front();
        q.pop();
        node->left=tree[index]==-1?nullptr:new TreeNode(tree[index++]);
        if(node->left){
            q.push(node->left);
        }else{
            index++;
        }
        node->right=tree[index]==-1?nullptr:new TreeNode(tree[index++]);
        if(node->right){
            q.push(node->right);
        }else{
            index++;
        }
    }
    TreeNode *node1=root->left,*node2=root->right;
    TreeNode *res=lowestCommonAncestor(root,node1,node2);
    std::cout<<res->val;
}