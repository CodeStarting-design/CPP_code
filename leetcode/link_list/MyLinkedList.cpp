#include<iostream>
using namespace std;
struct LinkedNode
    {
        int val;
        LinkedNode* next;
        LinkedNode(): val(0) , next(nullptr){}
    };
class MyLinkedList {
    public:
    int size;
    LinkedNode* head;
    MyLinkedList() { // 类的初始化函数
    this->size=0;
    this->head=new LinkedNode(); // 此处是创建了一个头结点
    }
    int get(int index) { //此处的index为索引，从0开始
    if(index<this->size){
        LinkedNode *p=this->head;
        for(int i=0;i<=index;p=p->next,i++);
        return p->val;
    }
    return -1;
    }
    
    void addAtHead(int val) {
        LinkedNode *p=new LinkedNode();
        p->val=val;
        p->next=this->head->next;
        this->head->next=p;
        this->size++;
    }
    
    void addAtTail(int val) {
        LinkedNode *p=this->head;
        while(p->next!=nullptr)
        p=p->next;
        LinkedNode *q=new LinkedNode();
        q->val=val;
        p->next=q;
        this->size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<=0)
        this->addAtHead(val);
        if(index==this->size)
        this->addAtTail(val);
        if(index>this->size)
        return ;
        if(index>0&&index<this->size){
        LinkedNode *q=this->head,*p=this->head->next;
        for(int i=0;i<index;q=p,p=p->next,i++);
        LinkedNode *t=new LinkedNode();
        t->val=val;
        q->next=t;
        t->next=p;
        this->size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index<this->size){
            LinkedNode *q=this->head,*p=q->next;
            for(int i=0;i<index;i++,q=p,p=p->next);
            q->next=p->next;
            free(p);
            this->size--;
        }
    }

};
int main(){
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    for(LinkedNode *p=obj->head->next;p!=nullptr;p=p->next)
    cout<<p->val<<"->";
    cout<<endl;
    obj->addAtTail(3);
    for(LinkedNode *p=obj->head->next;p!=nullptr;p=p->next)
    cout<<p->val<<"->";
    cout<<endl;
    obj->addAtIndex(1,2);
    for(LinkedNode *p=obj->head->next;p!=nullptr;p=p->next)
    cout<<p->val<<"->";
    cout<<endl;
    int param_1 = obj->get(1);
    cout<<param_1<<endl;
    obj->deleteAtIndex(1);
    for(LinkedNode *p=obj->head->next;p!=nullptr;p=p->next)
    cout<<p->val<<"->";
    cout<<endl;
    param_1 = obj->get(1);
    cout<<param_1<<endl;
    for(LinkedNode *p=obj->head->next;p!=nullptr;p=p->next)
    cout<<p->val<<"->";
    cout<<endl;
    return 0;
}