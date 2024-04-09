#include<vector>
#include<iostream>
#include<limits.h>
#include<algorithm>
using std::vector;
using std::swap;
class heap{
    vector<int> nums;
    int n;
    void adjust(int i){
        // 以i作为根节点开始向下调整
        for(int j=2*i;j<=n;j=j*2){
            if(j<n&&nums[j]>=nums[j+1])j++;
            if(nums[i]<=nums[j]) break;
            else {
                swap(nums[i],nums[j]);
                i=j;
            }
        }
    }
public:
    heap():nums(vector<int>(1)),n(0){}
    int top(){
        if(n!=0)return nums[1];
        return INT_MIN;
    }
    int pop(){
        if(n==0) return -1;
        swap(nums[1],nums[n]);
        nums.resize(n);
        n--;
        adjust(1);
        return 0;
    }
    void push(int num){
        nums.push_back(num);
        n++;
        for(int i=n/2;i>0;i=i/2){
            adjust(i);
        }
    }
    int getSize(){ return n;}
};
int findKthLargest(vector<int>& nums, int k) {
        heap h;
        for(int i=0;i<k;i++){
            h.push(nums[i]);
        }
        for(int j=k;j<nums.size();j++){
            if(h.top()<nums[j]){
                h.pop();
                h.push(nums[j]);
            }
        }
        return h.top();
    }
int main(){
    vector<int> nums={7,6,5,4,3,2,1};
    std::cout<<findKthLargest(nums,5);
}