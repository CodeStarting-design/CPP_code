#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::swap;
struct node{
    int num;
    int freq;
    bool operator>(const node& s){
        return freq>s.freq;
    }
    node(int n,int q):num(n),freq(q){}
};
class heap{
private:
    vector<node> nums;
    int n;
    void adjust(int i){
        for(int j=2*i;j<=n;j=j*2){
            if(j<n&&nums[j+1]>nums[j])j++;
            if(nums[i]>nums[j]) break;
            else{
                swap(nums[i],nums[j]);
                i=j;
            }
        }
    }
public:
    heap():n(0){
        nums.push_back(node(0,0));
    }
    void push(node a){
        nums.push_back(a);
        n++;
        for(int i=n;i>0;i=i/2){
            adjust(i);
        }
    }
    void pop(){
        if(n==0) return;
        swap(nums[1],nums[n]);
        nums.resize(n);
        n--;
        adjust(1);
    }
    node top(){
        return nums[1];
    }
    int getSize(){
        return n;
    }
};
int main(){

}