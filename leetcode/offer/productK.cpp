#include<iostream>
#include<vector>
using std::cout;
using std::vector;
 int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
        int res=0;
        int s=-1,e=-1;
        int product=1;
        cout<<nums.size()-1;
        while(e<3){
            product*=nums[++e];
            if(product<k){
                res+=e-s;
                continue;
            }
            while(s<e && product>=k){
                product/=nums[++s];
            }
            res+=e-s;
        }
        return res;
    }
int main(){
    vector<int> nums={10,5,2,6};
    cout<<numSubarrayProductLessThanK(nums,100);
}