#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> num(n);
    for(auto &a:num)
    cin>>a;
    for(int i=0;i<num.size()-1;i++)
    cout<<num[i]+num[i+1]<<" , ";
    cout<<endl;
    for(int i=0;i<(num.size())/2;i++)
    cout<<num[i]+num[num.size()-1-i]<<" , ";
    cout<<endl;
    return 0;
}