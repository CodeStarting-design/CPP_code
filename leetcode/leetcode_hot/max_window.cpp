#include<iostream>
#include<vector>
#include<algorithm>
using std::swap;
using std::vector;
struct elem{
    int num;
    int index;
    elem(int n,int i):num(n),index(i) {}
    elem()=default;
};
class prior_queue{
private:
    void adjust(int k){
        elem tmp=v[k];
        for(int i=2*k;i<v.size();i=2*i){
            if(i<v.size()-1&&v[i].num<v[i+1].num) i++;
            if(v[i].num<tmp.num) break;
            else{
                v[k]=v[i];
                k=i;
            }
        }
        v[k]=tmp;
    }
    vector<elem> v;
public:
    // 此处的初始化，严格意义上只需要使用默认的初始化函数，但是为了满足下标的特性，向v中插入一个元素
    prior_queue(){
        v.push_back(elem(-1,-1));
    }
    void push(elem e){
        v.push_back(e);
        for(int i=v.size()-1;i>0;i=i/2){
            adjust(i);
        }
    }
    elem front(){
        return v[1];
    }
    void pop(){
        swap(v[1],v[v.size()-1]);// 和最后一个元素交换
        v.pop_back();
        adjust(1);
    }
    bool empty(){
        return v.size()==1;
    }
};

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        prior_queue p_q;
        int left=0,right=0;
        vector<int> res;
        for(;right<k-1;right++){
            p_q.push(elem(nums[right],right));
        }
        res.push_back(p_q.front().num);
        while(right<nums.size()){
            p_q.push(elem(nums[right],right));
            left++;
            right++;
            while(p_q.front().index<left){
                p_q.pop();
            }
            res.push_back(p_q.front().num);
        }
        return res;
    }
int main(){
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    vector<int> res = maxSlidingWindow(nums,3);
    for(auto a:res) std::cout<<a<<std::endl;
}