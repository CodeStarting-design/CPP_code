#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> vec(n,vector<int>(n));
        // int starti=0,startj=0;
        // int i=0,j=0,len=n-1,num=1;
        // //len规定移次数
        // while(len>0){
        //     for(int move=0;move<len;vec[i][j]=num++,j++,move++);
        //     for(int move=0;move<len;vec[i][j]=num++,i++,move++);
        //     for(int move=0;move<len;vec[i][j]=num++,j--,move++);
        //     for(int move=0;move<len;vec[i][j]=num++,i--,move++);
        //     len-=2;
        //     i=++starti,j=++startj;
        // }
        // len==0?vec[i][j]=num:0;
        int l=0,r=n-1,t=0,b=n-1,num=1;
        int i=0,j=0;
        while(num<=(n*n)){
            for(i=t,j=l;j<=r;vec[i][j++]=num++);
            t++;
            for(i=t,j=r;i<=b;vec[i++][j]=num++);
            r--;
            for(i=b,j=r;j>=l;vec[i][j--]=num++);
            b--;
            for(i=b,j=l;i>=t;vec[i--][j]=num++);
            l++;
        }
        for(auto &a:vec){
            cout<<"[";
            for(auto &b:a){
                cout<<b<<" ";               
            }
            cout<<"]"<<endl;
        }
        
    return 0;
}
