#include<iostream>
#include<vector>
using namespace std ;
int main(){
    vector<int> grade(11,0);
    int n,num;
    cin>>n;
    auto it=grade.begin();
    for(int i=0; i<n;i++){
        cin>>num;
        if(num>=0&&num<=100)
        *(it+(num/10))+=1;
        else { cout<<"无效成绩"<<endl; break;}
    }
    for(it=grade.begin();it!=grade.end();it++)
    cout<<*it<<endl;
    return 0;
}