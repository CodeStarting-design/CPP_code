#include<iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {} //三种初始化函数
};
ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;
        ListNode *p=head,*pre=head; 
        //此处是不带头结点的链表元素的删除，那么在删除第一个元素的操作上就存在不同之处
        while(p!=nullptr){
            if(p->val==val){
                if(p==pre){
                    pre=p->next;
                    free(p);
                    p=pre;
                    head=p;
                }else{
                    pre->next=p->next;
                    free(p);
                    p=pre->next;
                }
            }else {
                pre=p;
                p=p->next;
            }
        }
        return head;
        
}
int main(){
    ListNode *head,*p;
    head=new ListNode(6);
    for(int i=5;i>0;i--){
        p=new ListNode(i);
        p->next=head;
        head=p;
    }
    head=removeElements(head,6);
    for(p=head;p!=nullptr;cout<<p->val<<endl,p=p->next);
    return 0;
}
