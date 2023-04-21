#include<iostream>
#include<stack>
#include<algorithm>
#include<queue>
#include<vector>
using std::stack;
using std::swap;
using std::vector;
using std::queue;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

    TreeNode* getFather(TreeNode*root,int key){
        TreeNode *node=root,*pre=nullptr;
        while(node&&node->val!=key){
            if(node->val>key) {
                pre=node;
                node=node->left;
            }
            else if(node->val<key) {
                pre=node;
                node=node->right;
            }
        }
        return pre;
    }
    TreeNode* getNext(TreeNode* root,int key){
       TreeNode* pre=nullptr;
       stack<TreeNode*> s;
       while(root||!s.empty()){
           while(root){
               s.push(root);
               root=root->left;
           }
           TreeNode* node=s.top();
           s.pop();
           if(pre&&pre->val==key) return node;
           pre=node;
           if(node->right){
               root=node->right;
           }
       }
       return nullptr;
    }
    TreeNode* getPre(TreeNode* root,int key){
       TreeNode* pre=nullptr;
       stack<TreeNode*> s;
       while(root||!s.empty()){
           while(root){
               s.push(root);
               root=root->left;
           }
           TreeNode* node=s.top();
           s.pop();
           if(node->val==key) return pre;
           pre=node;
           if(node->right){
               root=node->right;
           }
       }
       return nullptr;
    }
    TreeNode* deleteNode(TreeNode* &root, int key) {
        if(!root) return root;
        TreeNode *node=root,*pre=nullptr;
        while(node&&node->val!=key){
            if(node->val>key) {
                pre=node;
                node=node->left;
            }
            else if(node->val<key) {
                pre=node;
                node=node->right;
            }
        }
        if(!node) return root;
        if(node->left&&node->right){
            TreeNode* n_pre=getPre(node,key);
            TreeNode* n_father=getFather(node,pre->val);
            swap(node->val,n_pre->val);
            node=n_pre;
            pre=n_father;
        }
        if(!node->left&&!node->right){
            if(!pre){
                return pre;
            }
            if(node==pre->left){
                pre->left=nullptr;
            }else{
                pre->right=nullptr;
            }
            return root;
        }
        else{// 只有一个孩子
            if(node->left){
                if(pre->left==node){
                    pre->left=node->left;
                }else{
                    pre->right=node->left;
                }
            }else{
                if(pre->left==node){
                    pre->left=node->right;
                }else{
                    pre->right=node->right;
                }
            }
            return root;
        }
    }

void printTree(TreeNode* root){
    if(root){
        printTree(root->left);
        std::cout<<root->val<<" ";
        printTree(root->right);
    }
}
int main(){
    vector<int> tree={5,3,6,2,4,-1,7};
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
    TreeNode* node1=deleteNode(root,3);
    printTree(node1);
}