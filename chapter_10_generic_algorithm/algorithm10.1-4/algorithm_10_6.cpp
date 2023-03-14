#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> vec{1,2,3,4,5,6};
    fill_n(vec.begin(),vec.size(),0);
    for(auto a:vec)
    cout<<a<<" ";
    cout<<endl;
}