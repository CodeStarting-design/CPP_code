#include<unordered_set>
#include<iostream>
using std::unordered_set;
using std::cout;
    int get_res(int n){
        int res=0;
        while(n>0){
            int num=n%10;
            n=n/10;
            res+=num*num;
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);
        int res=get_res(n);
        while(res!=1&&s.find(res)==s.end()){
            s.insert(res);
            res=get_res(res);
        }
        return res==1;
        
    }
    int main(){
        cout<<isHappy(19)<<std::endl;
    }