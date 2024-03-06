#include<vector>
#include<iostream>
using std::vector;
int findRain(int& s,int& e,vector<int>& height){
        int n=height.size();
        int res=0;
        int tmp=0;
        while(e<n&&height[e]<height[s]){
            tmp-=height[e++];
        }
        if(e<n){
            res+=(e-s-1)*height[s]+tmp;
        }
        return res;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==1) return 0;
        int s=0,e=1;
        int res=0;
        while(e<n){// 先处理后续存在比当前高的
            int tmp=findRain(s,e,height);
            if(tmp){
                res+=tmp;
                s=e++;
            }
        }
        // 处理尾部的情形
        if(s==n-1) return res;
        s++;
        e=s+1;
        while(s<n-1){
            int tmp_s=s,tmp_e=e;
            int tmp=findRain(tmp_s,tmp_e,height);
            if(tmp){
                res+=tmp;
                s=tmp_e;
                e=tmp_e+1;
            }else{
                s++;
                e=s+1;
            }
        }
        return res;
    }
int main(){
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout<<trap(height);
    return 0;
}