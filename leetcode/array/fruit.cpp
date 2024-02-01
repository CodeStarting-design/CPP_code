 #include<iostream>
 #include<vector>
 using std::vector;
 bool is_same(int& num1,int& num2,int fruits){
     if(num1==fruits||num2==fruits){ // 此处一定需要先判断是否是满足，否则可能会将num1和num2置为相同的类型
            return true;
        }
        if(num1==-1){
            num1=fruits;
            return true;
        }
        if(num2==-1){
            num2=fruits;
            return true;
        }
        return false;
    }
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int end=0,start=0,num1=-1,num2=-1;
        int res=0;
        while(end<n){
            while(end<n && is_same(num1,num2,fruits[end])){
                res=end-start+1>res?end-start+1:res;
                end++;
            }// 此时说明扩展失败，重新选取起点
            if(end==n) return res;
            num1=fruits[end],num2=fruits[end-1];
            start=end-1;
            while(is_same(num1,num2,fruits[--start]));
            start++;
        }
        return res;

    }
    int main(){
        vector<int> f={3,3,3,1,2,1,1,2,3,3,4};
        std::cout<<totalFruit(f)<<std::endl;
    }