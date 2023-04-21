#include<iostream>
#include<vector>
#include<stack>
#include<utility>
using std::pair;
using std::vector;
using std::stack;
class Node {
public:
    int val;
    vector<Node*> children; //孩子节点的序列

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
    vector<int> preorder(Node* root) {
        vector<int> nodeList;
        if(!root) return nodeList;
        stack<pair<Node*,int>> s;
        Node *pre;
        while(root||!s.empty()){
            if(root){
                pre=root;
                s.push(pair(pre,1));
                nodeList.push_back(root->val);
                if(!root->children.empty()){
                    root=root->children.front(); // 此时是访问的第一个孩子节点
                }
                else root=nullptr;
            }else{
                pair<Node*,int> pNode=s.top();
                s.pop();
                pair<Node*,int> father=s.top();
                if(father.first->children.size()>pNode.second){
                    root=father.first->children[pNode.second];
                    nodeList.push_back(root->val);
                    s.push(pair(root,++pNode.second));
                }
            }
        }
        return nodeList;
    }

int main(){
    
}
