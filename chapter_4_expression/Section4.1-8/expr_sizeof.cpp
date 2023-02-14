#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    cout<<sizeof(int)<<endl; // 4
    int a=10,*p;
    cout<<sizeof a<<endl;    // 4
    cout<<sizeof p<<endl;    // 8
    int vec[10];
    cout<<sizeof vec<<endl; // 40
    vector<int> vec1(10),vec2(20);
    cout<<sizeof vec1<<" " <<sizeof vec2<<endl; // 24 24
    string str="deed";    
    cout<<sizeof str<<endl; // 32
    return 0;
}