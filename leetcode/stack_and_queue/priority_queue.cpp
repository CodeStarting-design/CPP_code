/* ************************************************************************
> File Name:     ./stack_and_queue/priority_queue.cpp
> Author:        mark
> Created Time:  2023年03月05日 星期日 20时17分20秒
> Description:   
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
struct elem{
    int val=0;
    int index=0;
    elem(int v,int i):val(v),index(i) {};
    elem()=default;
};
class priority_queue{
private:
    vector<elem> v1;
    void adjust_queue(int k){ // 调整以k为根的子树
        elem tmp=v1[k]; 
        for(int i=2*k;i<v1.size();i=2*i){
            if(i<v1.size()-1&&v1[i].val<v1[i+1].val)
                i++;
            if(tmp.val>v1[i].val) break; // 在三个节点中无需进行交换
            else{
                v1[k]=v1[i];
                k=i; // 迭代到子树中进行处理
            }
        }
        v1[k]=tmp;
    }
public:
    priority_queue(){
        v1.push_back(elem(-1,-1));
    }
    elem front(){
        return v1[1];
    }
    bool empty(){
        return v1.size()==1;
    }
    void push(elem e){
        v1.push_back(e); // 此处在尾部插入了一个元素，是不需要进行初始建堆的
        int k=v1.size()-1;
        for(int i=k;i>0;i=i/2)
            adjust_queue(i);
    }
    void pop(){
        swap(v1[1],v1[v1.size()-1]);
        int n=v1.size();
        v1.resize(n-1);
        adjust_queue(1);
    }
    void print(){
        for(int i=1;i<v1.size();i++)
            cout<<v1[i].val<<" ";
        cout<<endl;
    }
};
int main(){
    vector<int> vec={
         12,3,4,6,1,4,0
    };
    priority_queue q1;
    for(int i=0;i<vec.size();i++){
       q1.push(elem(vec[i],i));
    }
    q1.print();
    q1.pop();
    q1.print();
    q1.push(elem(14,8));
    q1.print();
}
