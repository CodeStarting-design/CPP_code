#ifndef copy_control_13_28_h
#define copy_control_13_28_h
#include<string>
using std::string;
class TreeNode{// 结点值
public:
    TreeNode():left(nullptr),right(nullptr),count(new int(1)){}
    TreeNode(const TreeNode& Node){
        left=Node.left;
        right=Node.right;
        value=Node.value;
        count=Node.count;
        *count++;
    }
    TreeNode& operator=(const TreeNode&);
    ~TreeNode(){
        if(--*count==0){
            if(left){
                delete left;
                left=nullptr;
            }
            if(right){
                delete right;
                right=nullptr;
            }
            delete count;
            count=nullptr;
        }
    }
private:
string value;
int* count; // 此处使用count进行计数
TreeNode*left;
TreeNode*right;
};
class BinstrTree{// 二叉树
public:// 此处不考虑root指针中的count值计数，直接删除即可
    BinstrTree():root(new TreeNode()){} 
    BinstrTree(const BinstrTree& BT){// 拷贝构造函数
        root=new TreeNode(*BT.root);
    }
    BinstrTree& operator=(const BinstrTree& BT){ // 此处采用值拷贝的方式
        auto tmp=new TreeNode(*BT.root);
        delete root;
        root=tmp;
        return *this;
    }
    ~BinstrTree(){
        delete root;
    }
private:
    TreeNode *root;
};
// 都是指针拷贝
// 此处对于left，right指针的理解，可以理解为，当前结点作为父结点，要是父结点都被删除了，那么子节点也就丢失了可以寻址的位置，那么也就将子结点所占用的内存空间进行释放

TreeNode& TreeNode::operator=(const TreeNode& Node){
    (*Node.count)++;// 先加加的方式避免了自身赋值给自身出错的问题
    if(--*count==0){
        if(left){
            delete left;
            left=nullptr;
        }
        if(right){
            delete right;
            right=nullptr;
        }
        delete count;
        count=nullptr;
    }
    count=Node.count;
    left=Node.left;
    right=Node.right;
    value=Node.value;
    return *this;
}
#endif