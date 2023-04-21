#include<iostream>
#include<vector>
using std::vector;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


    int find_index(vector<int> order,int val){
        int i;
        for(i=0;i<order.size()&&order[i]!=val;i++);
        return (i==order.size())?-1:i;
    }
    void build(TreeNode* &root,vector<int> inorder,int i_left,int i_right,vector<int> postorder,int p_left,int p_right){
        if(i_left<=i_right){
            int root_val=postorder[p_right];
            int index=find_index(inorder,root_val);
            int right_num=i_right-index;
            root=new TreeNode(root_val);
            build(root->left,inorder,i_left,index-1,postorder,p_left,p_right-right_num-1);
            build(root->right,inorder,index+1,i_right,postorder,p_right-right_num,p_right-1);
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root=nullptr;
        build(root,inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
        return root;
    }
void print_tree(TreeNode* root){
    if(root){
        std::cout<<root->val<<" ";
        print_tree(root->left);
        print_tree(root->right);
    }
}


int main(){
    vector<int> inorder={9,3,15,20,7};
    vector<int> postorder={9,15,7,20,3};
    TreeNode *root=nullptr;
    root=buildTree(inorder,postorder);
    print_tree(root);
}